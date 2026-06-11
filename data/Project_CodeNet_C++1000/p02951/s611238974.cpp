/*
        @uthor: Kashish Gilhotra
        user: CodeChef, CodeForces, HackerEarth, HackerRank, SPOJ: kashish001
*/

#include <bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
  
#define int long long int 
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

double EPS = 1e-9; 
int INF = 1000000005; 
long long INFF = 1000000000000000005LL;
const int mod = 1e9 + 7; 

//#define CI cpp_int
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define RESET(a, b) memset(a, b, sizeof(a)) 
#define deb(...) cout << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " 
#define EB emplace_back
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define size(v) (int)v.size() 
#define endl "\n"
#define SINT int32_t
#define UMO unordered_map
#define USO unordered_set
#define UB(v, n) upper_bound(ALL(v), n)
#define LB(v, n) lower_bound(ALL(v), n)
#define to_bin(b, n) bitset<b>(n) // Provide binary representation of a Number
#define setBits(n) popcount(n) // count Set Bits in a Number
#define MX *max_element
#define MN *min_element
#define TC int t; cin >> t; while (t--) 
int popcount(uint32_t n)
{
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    return ((n + ((n >> 4) & 0xF0F0F0F)) * 0x1010101) >> 24;
}

void Panda() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b) cout << c << endl;
    else if((a - b) >= c) cout << 0 << endl;
    else cout << c - (a - b) << endl;
}
  
int32_t main() 
{ 
    FAST;

    
    Panda();

    return 0; 
} 