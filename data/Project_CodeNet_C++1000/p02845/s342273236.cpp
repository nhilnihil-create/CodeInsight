#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n;
    //cout<<n<<endl;
    cin>>n;
    //cout<<n<<endl;
    vi c={0,0,0};
    ll ans=1;
    //cout<<n<<endl;
    rep(i,n){
        //cout<<111<<endl;
        int a;
        cin>>a;
        if (c[0]==a){
            if (c[1]==a){
                if (c[2]==a){
                    ans*=3;
                    ans%=MOD;
                }
                else{
                    ans*=2;
                    ans%=MOD;
                }
            }
            c[0]+=1;
        }
        else if (c[1]==a){
            if (c[2]==a){
                ans*=2;
                ans%=MOD;
            }
            c[1]+=1;
        }
        else if (c[2]==a)c[2]+=1;
        else ans=0;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}