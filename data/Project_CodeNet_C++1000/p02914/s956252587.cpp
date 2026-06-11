    #include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
}

const int N = 1e5 + 10, LOG_A = 60;

ll basis[LOG_A];

vector <ll> shifts;

void insertVector(ll mask) {
    for (ll i = LOG_A - 1; i >= 0; i--) {
        if ((mask & shifts[i]) == 0) continue;

        if (!basis[i]) {
            basis[i] = mask;
            return;
        }

        mask ^= basis[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll x=0;
    shifts.resize(60);
    shifts[0]=1;
    for(ll i=1;i<=59;i++)
        shifts[i]=shifts[i-1]*2;

    ll data[n];
    for(int i=0;i<n;i++) {
        cin >> data[i];
        //insertVector(data[i]);
        x ^= data[i];
    }
    
    for(int i=0;i<60;i++) {
        if (x & shifts[i]) {
            for(int j=0;j<n;j++) {
                if (data[j] & shifts[i]) data[j] -= shifts[i];
            }
        }
    }
    
    for(int i=0;i<n;i++) insertVector(data[i]);

    ll ans = 0;

    for (ll i = LOG_A - 1; i >= 0; i--) {
        if (!basis[i]) continue;

        if (ans & shifts[i]) continue;

        ans ^= basis[i];
    }
    //cout<<ans<<endl;

    ll test=x;
    
    for(ll i=59;i>=0;i--)
    {
        if(!(x&shifts[i])&&ans&shifts[i])
            test+=(power(2,i+1,2e18));
    }

    cout << test << endl;
   //cout << (ans + (x ^ ans)) << endl;
    
    
    return 0;   
}


 
 
