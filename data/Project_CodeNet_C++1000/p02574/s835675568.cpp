#include <bits/stdc++.h>
#define load ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
#define ll long long
#define ull unsigned long long
#define fori(i,n) for (int i=0; i<int(n);i++)
#define srt(v) sort(v.begin(), v.end())
#define MOD 1000000007
const int INF = 1e9;
const double PI = 3.14159265358979323846;
ll gcd(ll a, ll b) {
    return b != 0 ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
ll spow(ll base, ll exp){
	ll ans = 1;
	for(ll i=0;i<exp;i++) ans = ans * base % MOD;
	return ans;
}
ll divide(ll a, ll b){
	return a * spow(b, MOD-2) % MOD;
}
template<typename T> void print(const T &x){cout<<x<<endl;}
template<typename T=int> vector<T> read(size_t n){
  vector<T> arr(n);
  for(size_t i=0;i<n;i++) cin>>arr[i];
  return arr;
}

void solve(){
	
}

int main(){
	//~ load;
	//~ int t;
	//~ cin >> t;
	//~ while(t--){
		//~ solve();
	//~ }
	
	int n;
	cin >> n;
	auto v = read(n);
	int result = v[0];
	int maxNum = v[0];
	for(int x : v){
		result = __gcd(result, x);
		maxNum = max(maxNum, x);
	}
	if (result != 1){
		print("not coprime\n");
		return 0;
	}
	
	vector<int> prime(maxNum + 1, 0);
	// build the sieve of eratosthenes
	for(int i=2; i<=maxNum; i++){
		if(prime[i]) continue;
		for(int j=i; j<=maxNum; j+=i){
			prime[j] = i;
		}
	}

	// check the prime if duplicate or not, if yes then setwise
	unordered_map<int, int> m;
	for(int x : v){
		int temp = x;
		while(temp != 1){
			int p = prime[temp];
			while(temp%p == 0){
				temp /= p;
			}
			m[p]++;
		}
	}
	for(auto x : m){
		if (x.second > 1){
			print("setwise coprime\n");
			return 0;
		}
	}
	print("pairwise coprime\n");
}

