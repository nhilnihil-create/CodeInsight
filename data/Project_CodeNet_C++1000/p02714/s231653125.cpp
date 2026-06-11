//HOW YOU DOI'N........................JT
//Could this code be more bad..........CB
//I know...............................MG
//Hii..................................RG
//Noooooooo............................RG
//I wish I could but I don't want to...PB

//That's what she said.................MS


#include <bits/stdc++.h>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define ll long long
#define ld long double
#define pb push_back
#define mkpr make_pair
#define fi(i,a,b) for (ll i=a;i<b;i++)
#define vll vector<ll>
#define vch vector<char>
#define vst vector<string>
#define vpll vector<pll>
#define vvl vector<vector<ll>>
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define mxe(v) *max_element(v.begin(),v.end())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define mll map<ll, ll>
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*1ll * (b)) / gcd(a, b)
#define nl "\n"
#define sp " "
#define sz(x)  (int)x.size()

using namespace std;

double PI = (acos(-1));
ll md = 1000000007;
//ll md = 998244353;

ll pw(ll a, ll b){ll c=1,m=a;while (b){if (b&1)c=(c*m);m=(m*m);b/=2;}return c;}
ll pwmd(ll a, ll b){ll c = 1, m = a;while (b){if (b & 1)c = ((c * m)) % md;m = (m * m) % md;b /= 2;}return c;}
ll modinv(ll n){return pwmd(n, md - 2);}
ll min(ll a,ll b){if(a>=b)return b;return a;}
ll nc2(ll n){return (1ll * n * (n - 1)) / 2;}
ll nsum(ll n){return (1ll * n * (n + 1)) / 2;}
bool prime(ll a){for(int i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}

#define MAX_SIZE 1005
void Sieve(vector<int> &primes){bool IsPrime[MAX_SIZE];memset(IsPrime, true, sizeof(IsPrime));
for (int p = 2; p * p < MAX_SIZE; p++){if (IsPrime[p] == true){
			for (int i = p * p; i < MAX_SIZE; i += p)IsPrime[i] = false;}}
	for (int p = 2; p < MAX_SIZE; p++)if (IsPrime[p])primes.push_back(p);}


vector<char> sml={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<char> cap={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};



// Lets start ...

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    ll ans=0;
    fi(i,1,n-1){
        vll v(3,0);
    vector<char>ve={'R','G','B'};
    fi(j,0,i){
        if(s[j]=='R')v[0]++;
        else if(s[j]=='G')v[1]++;
        else v[2]++;
    }
        fi(j,i+1,n){
            if(s[i]==s[j])continue;
            else{mll mp;
            ll a;
                fi(k,0,3){
                    if(s[i]==ve[k])mp[k]++;
                    if(s[j]==ve[k])mp[k]++,a=k;
                }ll cur=0;
                fi(k,0,3){
                    if(mp[k]==0)cur=k;
                }
                if(i-j+i>=0&&s[i-j+i]==ve[cur])ans+=(v[cur]-1);
                else ans+=(v[cur]);
            }
        }
    }
    cout<<ans;
}



int main(){
    //vector<int> primes;
    //Sieve(primes);

    fast
    ll tests=1;
    //cin>>tests;
    while(tests--){
        solve();
    }

    return 0;
    }

// Done:)







