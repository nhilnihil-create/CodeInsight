#include<bits/stdc++.h>
using namespace std;
#define fastIO(); ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fr(i,a,b) for(lli i=a;i<b;i++)
#define f0(a,b) for(lli i=a;i<b;i++)
#define fn(b,a) for(lli i=b;i>a;i--)
#define dbg(x); cout<<"\n"<<#x<<": "<<x;
#define ret return
#define pb push_back
#define pf push_front
#define mp make_pair
#define sq(a) (a)*(a)
#define fs first
#define sc second
#define el "\n"
#define brk break
#define cont continue
#define all(a) a.begin(),a.end()
#define E9 1000000007
#define E5 100007
#define INF 1e18+7
typedef long long int lli;  //  e-18 to e18
typedef vector<int> vi;
typedef set<int> si;
typedef string str;
typedef map<int,int> mii;
typedef vector<long long int> vll;
typedef pair<long long int,long long int> pll;
typedef vector<vector<long long int>> vvll;
void solve(){
    lli n,k;
    cin >> n >> k; 
    vll a(n+1);
	for(lli i = 1; i <= n; i++) cin >> a[i]; 
	lli ans = 0, K = (k * (k + 1) / 2) % E9, KK = (k * (k - 1) / 2) % E9; 
	for(lli i = 1; i <= n; i++) {
		lli l = 0, r = 0; 
		for(lli j = 1; j < i; j++) l += (a[j] > a[i]); 
		for(lli j = i + 1; j <= n; j++) r += (a[j] > a[i]); 
		ans = (ans + l * K % E9 + r * KK % E9) % E9; 
	}
	cout << ans << el; 
}
int main(){
    fastIO();
    lli t(1);
    // cin>>t;
    while(t--) solve();
    ret 0; 
}

// compilation flags

// normal
//      g++ -std=c++17 -O2 -Wall a.cpp -o a
// fast running time
//      g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
// check for mistakes
//      g++ -std=c++17 -Wshadow -Wall -o a a.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

// use digit separator for better readbility e.g. 10000000 (base 10 - decimal) =  1'000'0'000' (separate at every 3 digits)
// 0b0101000 (base 2 - binary ) =  0b010'1000' (separate at every 4 digits-nibble)
// integer literals - suffixes and prefixes e.g. 0b1010 = binary - prefix for base of number
// 0x9A01 = hexadecimal
// 0733 = octal
// 153 = decimal
// 1645241684131 ll =  suffix for data type here long long int lly for others
// use M_PI for value of pi
// and check function defination for every new function used

// snippets

//     int n,k;
//     cin>>n>>k;
//     vi a(n);
//     f0(0,n) cin>>a[i];
