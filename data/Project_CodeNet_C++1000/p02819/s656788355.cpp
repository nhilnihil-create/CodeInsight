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
bool isPrime[maxx+1];

void sieve(){
    primes.clear();
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=maxx;i++){
        if(isPrime[i]){
            for(int j=i*i;j<maxx;j+=i){
                isPrime[j]=false;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<maxx;i+=2){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

// bool isPrime(int n){
//     if(n==2){return 1;}
//     if(n%2==0){return 0;}
//     if(n<2){return 0;}
//     for(int i=3;i*i<=n;i+=2){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return 1;
// }
int nextPrime(int n){
    sieve();
    return *upper_bound(all(primes),n-1);
}
void solve(){
    int n;
    cin>>n;
    cout<<nextPrime(n);
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