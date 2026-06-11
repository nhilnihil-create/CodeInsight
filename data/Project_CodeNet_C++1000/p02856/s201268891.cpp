#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int m;
    cin>>m;

    ll sum=0,dig=0;
    rep(i,m){
        int d;
        ll c;
        cin>>d>>c;
        sum+=d*c;
        dig+=c;
    }

    cout<<dig-1+((sum-1)/9)<<endl;

}
