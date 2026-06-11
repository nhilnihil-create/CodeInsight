#include <bits/stdc++.h>
#include <string>
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
#define S second　//pairの二つ目の要素


int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> p(n);
    rep(i,n){
        int x,l;
        cin>>x>>l;
        p[i]=pair<int,int>(x+l, x-l);
    }
    sort(p.begin(),p.end());
    int ans=1;
    int t=p[0].first;
    for(int i=1;i<n;i++){
        if(p[i].second>=t){
            ans++;
            t=p[i].first;
        }
    }
    cout<<ans<<endl;
    return 0;
}