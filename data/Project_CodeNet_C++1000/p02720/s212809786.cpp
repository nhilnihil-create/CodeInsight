#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素


int main(){
    int K;
    cin>>K;
    queue<ll> Q;
    for(int i=1;i<=9;i++) Q.push(i);
    int i=0;
    ll a;
    while(i<K){
        a=Q.front();
        i++;
        Q.pop();
        ll n=a*10;
        if(a%10!=0) Q.push(n+a%10-1);
        Q.push(n+a%10);
        if(a%10!=9) Q.push(n+a%10+1);
    }
    cout<<a<<endl;
    return 0;
}
