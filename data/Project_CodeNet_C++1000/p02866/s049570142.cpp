#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    ll n;
    cin >> n;
    map<ll,ll> data;
    ll Max = -1;
    int check = 1;
    rep(i,0,n){
        ll a;
        cin >> a;
        if(i==0&&a!=0){
            check = 0;
        }
        Max = max(Max,a);
        data[a]++;
    }
    if(check==0){
        cout<<0<<endl;
    }else if(data[0]!=1){
        cout<<0<<endl;
    }else{
        ll ans = 1;
        rep(i,1,Max){
            ll kake = 1;
            rep(j,0,data[i+1]){
                kake*=data[i];
                kake %= 998244353;
            }
            //ll kake = pow(data[i],data[i+1]);
            //kake %= 998244353;
            ans *= kake;
            ans %= 998244353;
        }
        cout<<ans<<endl;
    }
    
    

    return 0;
}
