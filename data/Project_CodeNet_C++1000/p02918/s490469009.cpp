#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

string S;

void rev(int l, int r){
    string temp=S;
    int e=r-l;
    for(int i=0;i<=e;i++){
        S[l+i]=(temp[r-i]=='R')? 'L' : 'R';
    }
}

int main(){
    int N,K;
    cin>>N>>K;
    cin>>S;
    int g=1;
    char c=S[0];
    for(int i=1;i<N;i++){
        if(S[i]!=c){
            g++;
            c=S[i];
        }
    }
    rep(i,K){
        g=max(1,g-2);
        if(g==0) break;
    }
    int ans=N-1-(g-1);
    cout<<ans<<endl;
    return 0;
}