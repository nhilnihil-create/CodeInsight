#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

const int INF=1001001001;

int N;
int S[1<<18];

queue<int>bucket[20];
signed main(){
	cin>>N;
	rep(i,1<<N)cin>>S[i];
	sort(S,S+(1<<N));

	bucket[N].push(INF);
	for(int i=(1<<N)-1;i>=0;i--){
		bool ok=false;
		for(int k=N;k>=0;k--){
			if(bucket[k].size()==0||bucket[k].front()==S[i])continue;
			ok=true;
			bucket[k].pop();
			for(int l=0;l<k;l++)bucket[l].push(S[i]);
			break;
		}
		if(!ok){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}