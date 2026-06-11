#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()0
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!
vector<int> primes;

void sieve(){
    primes.clear() ;   
}

bool isPrime(int n){
    if(n==2){return 1;}
    if(n%2==0){return 0;}
    if(n<2){return 0;}
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return 1;
}
void solve(){
    int n;
    cin>>n;
    while(1){
        if(isPrime(n)){
            cout<<n<<endl;
            return ;
        }
        n++;
    }
}

 
int main() {
    faster;
    int t=1;
    // cin>>t;
    
    while(t-->0){
        solve();
    }
	return 0;
}