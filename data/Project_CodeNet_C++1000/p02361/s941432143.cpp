#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
//#define rep(i,n) for(int i=0;i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long int lli;
typedef pair<lli,int> mp;

int n,m,st;
vector<mp> vs[100005];//グラフの情報を持つ
lli dist[100005];//距離を持つ

int main(void){
	scanf("%d%d%d",&n,&m,&st);
	rep(i,m){
		int a,b;
		lli c;
		scanf("%d%d%lld",&a,&b,&c);
		vs[a].push_back( mp(c,b) );
	}
	
	memset(dist,-1,sizeof(dist));//最初は、無限大で初期化
	
	priority_queue<mp,vector<mp>,greater<mp> > que;
	
	que.push(mp(0,st));//stには0で行ける
	
	while(!que.empty()){//queが空になるまでやる
		
		mp pa = que.top();
		que.pop();
		//queの先頭要素(一番軽いの)を取り出す。
		
		int no = pa.second;//今の頂点
		lli co = pa.first;//今の距離
		
		if(dist[no]!=-1)continue; //もし、すでに確定していたら、飛ばす
		
		dist[no] = co;//確定させる
		
		rep(i,vs[no].size()){//今の地点から出ているすべての辺の先について、キューに突っ込んでいく
			int to = vs[no][i].second;//次の頂点
			lli tc = co + vs[no][i].first;//次の距離
			
			if(dist[to]!=-1)continue; //もし、すでに確定していたら、飛ばす
			que.push( mp(tc,to) ); //queに追加
		}
	}
	//これで、全ての頂点について、stからの距離が求まった
	
	rep(i,n){
		if(dist[i]==-1)printf("INF\n");//もし-1なら、その頂点には到達不可のう
		else printf("%lld\n",dist[i]);//そうでなければ、距離を出力
	}
	
	return 0;
}

/*
ちなみに、上の
「もし-1なら、その頂点には到達不可のう」
のコメントの、
「のう」の字を「能」にしたところ、
まともに動かなくなったことを、ここに付記しておきます。
*/