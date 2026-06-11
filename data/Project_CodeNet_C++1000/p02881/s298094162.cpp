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
const int mod = 1e9 + 7; 

//#define CI cpp_int
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " 
#define EB emplace_back
#define ALL(v) v.begin(), v.end() 
#define size(v) (int)v.size() 
#define endl "\n"
#define UMO unordered_map
#define USO unordered_set
#define setBits(n) __builtin_popcountll(n)
#define TC int t; cin >> t; while (t--) 

void Panda() {
    int n;
    cin >> n;
    int minn = INT64_MAX;
    for(int i = 1; i <= sqrt(n) + 1; i++) {
    	if(n % i == 0) {
    		int ans = (n / i) - 1 + (i - 1);
    		debug(ans);
    		minn = min(ans, minn);
    	}
    }
    cout << minn << endl;
}
  
int32_t main() {
 
    FAST;

   
    
    Panda();

    return 0; 
} 