#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>
#include <numeric>

using namespace std;

#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define ll long long
#define ld long double

struct XX{
    int l;
    int r;
    int len;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.len) == (riRight.len)){
            return riLeft.l > riRight.l;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.len) < (riRight.len);
    }
};


//map<long long,long long> prime_f(long long n){
//    map<long long,long long>res;
//    for(int i=2;i*i<=n;i++){
//        while(n%i==0){
//            ++res[i];
//            n/=i;
//        }
//    }
//    if(n!=1)res[n]=1;
//    return res;
//}

//int n;
////int dat[2*10000000];
////int dat2[2*10000000];
//int dat[10];
//int dat2[10];
//
//void init(int n_){
//    n=1;
//    while(n<n_)n*=2;
//    for(int i=0;i<2*n-1;i++){
//        dat[i]=0;
//        dat2[i]=0;
//    }
//}
//
//void initset(int k,int a){
//    k+=n-1;
//    dat[k]=a;
//    while(k>0){
//        k=(k-1)/2;
//        dat[k]=dat[k*2+1]+dat[k*2+2];
//    }
//}
//
////[a,b)の間を[l,r]区間で比較しアップデート
////引数のindexに注意
////nは固定。initで計算すみ
////update2(L[i],R[i]+1,0,0,n,D[i]);
//void update2(int a,int b,int k,int l,int r,int v){//v更新値、区間は0-index
//    if(r<=a || b<=l)return;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=v*(r-l);
//        return;
//    }else{
//        update2(a,b,k*2+1,l,(l+r)/2,v);
//        update2(a,b,k*2+2,(l+r)/2,r,v);
//        return;
//    }
//}
//
//int query(int a,int b,int k,int l,int r){
//    if(r<=a || b<=l)return 0;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=0;
//        return dat[k];
//    }
//    else{
//        int vl=query(a,b,k*2+1,l,(l+r)/2);
//        int vr=query(a,b,k*2+2,(l+r)/2,r);
//        return vl+vr;
//    }
//}



//void printb(unsigned int v) {
//    unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
//    do putchar(mask & v ? '1' : '0');
//    while (mask >>= 1);
//}


#ifdef DEBUG
vector<int>G[300];//G[各頂点番号]
int d[300];
#else
vector<int>G[300001];//G[各頂点番号]
int d[300001];
#endif


typedef pair<int,int> P;//first:最短距離、second:頂点番号

//int prv[100001];//経路

void dijkstra(int s,int V){//V:頂点数
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+V+1,INT_MAX);
    //fill(prv,prv+V+1,-1);
    d[s]=0;
    que.push(P(0,s));
    
    while(!que.empty()){
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first){
            continue;
        }
        for(int i=0;i<G[v].size();i++){
            int e=G[v][i];
            if(d[e]>d[v]+1){
                d[e]=d[v]+1;
                que.push(P(d[e],e));
                //prv[e.to]=v;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs("05");//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int t1,t2;
        cin>>t1>>t2;
        t1--;t2--;
        G[t1].push_back(N+t2);
        G[N+t1].push_back(2*N+t2);
        G[2*N+t1].push_back(t2);
    }
    int start,end;
    cin>>start>>end;
    start--;end--;
    dijkstra(start,3*N);
    int ans=INT_MAX;
    if(d[end]%3==0){
        ans=min(ans,d[end]/3);
    }
    if(d[N+end]%3==0){
        ans=min(ans,d[end]/3);
    }
    if(d[2*N+end]%3==0){
        ans=min(ans,d[end]/3);
    }
    if(ans!=INT_MAX){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    //ここまで
    //cout << "ans" << endl;
    //cout << " " << "ans" << endl;
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}
