#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i < (n); ++i)
#define repD(i, a, n) for(ll i = a; i > (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (long long) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
// #define mp make_pair
#define pb push_back
// #define endl "\n"
#define MAXN 5000000
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<double> vd;
typedef vector<pii> vii;
int Ceil(int a, int b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
ll p=1000000007;
float E = 0.00000000000001;
ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        ll q=power(x,y/2);
        q=q%p;
        return (q*q)%p;
    }
    ll q=power(x,y/2);
    q=q%p;
    return ((x%p)*((q*q)%p))%p; 
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

bool isPowerOfTwo (int x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}  

long long int gcd(long long int a, long long int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a); 
}
long long int mod(long long int a, long long int b) {
    long long int ret = a%b; return ret>=0? ret: ret+b; 
}

int powerCount(int num, int x){
    int count = 0;
    while(!(num%x)){
        count++;
        num/=x;
    }
    return count;
}

vector <int> SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    vector<int> vec;
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
       if (prime[p]) {
        vec.push_back(p);
          // cout << p << " ";
        } 
    return vec;
}
long long numberOfPaths(int m, int n) 
{ 
    // We have to calculate m+n-2 C n-1 here 
    // which will be (m+n-2)! / (n-1)! (m-1)! 
    long long path = 1; 
    if(m<n){
	    for (long long i = n; i < (m + n - 1); i++) { 
	        path *= i; 
	        path /= (i - n + 1); 
	    } 
	}
	else{
		for (long long i = m; i < (m + n - 1); i++) { 
	        path *= i; 
	        path /= (i - m + 1); 
	    } 
	}
    return path; 
} 

class UnionFind{
    vector <int> parent;
    public:
        UnionFind(int n, bool oneBasedIndexing = false){
            if(oneBasedIndexing)
                n++; 
            parent.resize(n);
            for(int i = 0 ; i < n ; i++)
                make_set(i);
        }
        void make_set(int v){
            parent[v] = v;
        }
        int find_set(int v){
            if(parent[v] == v)
                return v;
            parent[v] = find_set(parent[v]);
            return parent[v];
        }
        void union_sets(int a, int b){
            int root_a = find_set(a);
            int root_b = find_set(b);
            parent[root_a] = root_b;
        }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
    	int n;
    	cin>>n;
    	vector <long long> vec(n+1);
    	ll maxn = 10000000000000000;
    	for(int i = 0 ; i < n+1 ; i++)
    		cin>>vec[i];
    	vector <long long> acc(n+1);
    	long long pow = 1;
    	for(int i = 0 ; i < n+1 ; i++){
    		acc[i] = pow - vec[i];
    		// cout<<pow<<endl;
    		if(acc[i] < 0){
    			// cout<<i<<" "<<pow<<endl;
    			cout<<"-1";
    			return 0;
    		}
    		// if(acc[i] == 0 && i != n){
    		// 	cout<<"-1";
    		// 	return 0;
    		// }
    		pow = min(acc[i]*2, maxn);
    	}
    	long long ans = 0, curr;
    	ans += vec[n];
    	curr = ans;
    	// for(auto x:acc)
    	// 	cout<<x<<" ";
    	// cout<<endl;
    	for(int i = n-1 ; i >= 0 ; i--){
    		// cout<<ans<<endl;
    		ans += min(acc[i]+vec[i], curr+vec[i]);
    		curr = min(acc[i]+vec[i], curr+vec[i]);
    		// curr += vec[i];
    	}
    	cout<<ans;
    }
    return 0;
}