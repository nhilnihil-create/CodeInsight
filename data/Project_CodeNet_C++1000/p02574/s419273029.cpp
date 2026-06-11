#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

const long long maxprime = 1e6 + 5;
bitset <maxprime> is_prime;
vector <long long> primes;
vector <long long>  factors;


//Gera uma lista de números primos até maxprime
//Funciona bem até 10^7
//Complexidade O(N log log N)
void SieveOfEratosthenes(){
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;

  for(long long i = 2;i<=maxprime;i++){
    if(is_prime[i]){
      primes.push_back(i);
      for(long long j = i*i;j<=maxprime;j+=i){
        is_prime[j] = 0;
      }
    }
  }
}

//Gera uma lista dos fatores primos de N
//Complexidade O(sqrt(N)/ln sqrt(N))
set<ll> primeFactors(long long N){
  int idx = 0;
  long long pf = primes[idx];
  set<ll> f;
  while(pf*pf <= N){
    while(N%pf == 0){
      N /= pf;
      f.insert(pf);
    }
    pf = primes[++idx];
  }

  if(N != 1){
    f.insert(N);
  }
    return f;
}


void solve(){
    SieveOfEratosthenes();
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &b: a) cin >> b;
    map<ll, ll> cnt;
    for (auto x : a){
        auto f = primeFactors(x);
        for (auto y : f) cnt[y]++;
    }
    bool pw = true;
    for (auto k : cnt){
        if (k.s > 1) {
            pw = false;
            break;
        }
    }
    if (pw){
        cout << "pairwise coprime\n";
        return;
    }
    ll gcd = a[0];
    for (int i = 0; i < n; ++i){
        gcd = __gcd(gcd, a[i]);
    }
    if (gcd != 1){
        cout << "not coprime\n";
    }
    else cout << "setwise coprime\n";
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}

