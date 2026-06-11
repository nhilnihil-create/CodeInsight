#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>

typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e18;
const ll N = 3e5;
const ll bits = 20;
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll p = 29;


int main(){

    FASTIO;
    PRECISION; 

    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll ans = 0;
    if(p==2||p==5){
        for(ll i=0;i<n;i++){
            ll dig = s[i]-'0';
            if(dig%p==0){
                ans+=i+1LL;
            }
        }
    }else{
        map<ll,ll>dp;
        dp[0] = 1;
        ll sum = 0;
        ll ft = 1;
        for(ll i=n-1;i>=0;i--){
            ll dig = s[i]-'0';
            sum = (dig*ft + sum)%p;
            ans+=dp[sum];
            dp[sum]++;
            ft = (ft*10LL)%p;
        }
    }

    cout<<ans<<"\n";

}
