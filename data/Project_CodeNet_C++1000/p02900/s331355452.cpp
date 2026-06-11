/* Ahmed Maher ( Acro_14 ) */
/*while(WA)try();*/
#include <bits/stdc++.h>
typedef long long ll;
const ll oo = 0x3f3f3f3f;
int const N = 1e6+5;
int const mod = 1e9+7;
using namespace std;
/*string Alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet="abcdefghijklmnopqrstuvwxyz";*/
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
vector<pair<ll, ll>>prime; 
void prime_fuct(ll x){
    for (ll i = 2; i * i <= x; i++){
        if(x % i == 0){
            pair<ll, ll> p = {i,0};
            while (x % i == 0){
                x /= i;
                p.second++;
            }
            prime.push_back(p);
        }
    }
    if(x > 1){
        pair<ll, ll> p = {x,1};
        prime.push_back(p);
    }
}

void solve(){
	ll a,b;
    cin>>a>>b;
    prime_fuct(gcd(a,b));
    cout<<(ll)prime.size()+1;
	cout<<endl;
}

int main()
{
  int t;
	t=1;
     while(t--)
    {
       
		solve();
 
    }
	return 0;
}
 
//       int anss[t+1]; 
//            anss[j]=ans;
//     for(int j=1;j<=t;j++) printf("Case %d: %d\n",j,anss[j]);