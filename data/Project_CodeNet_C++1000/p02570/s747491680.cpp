/*
        @uthor: Kashish Gilhotra
        user: CodeChef, CodeForces, HackerEarth, HackerRank, SPOJ: kashish001
*/

#include <bits/stdc++.h>
using namespace std;
  
#define int long long int 
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vi> vvi;
const int mod = 1e9 + 7; 

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " 
#define EB emplace_back
#define ALL(v) v.begin(), v.end() 
#define size(v) (int)v.size() 
#define endl "\n"
#define UMO unordered_map
#define USO unordered_set
#define TC int t; cin >> t; while (t--) 

void Panda() {
    float d, t, s;
    cin >> d >> t >> s;
    if(d / s <= t) cout << "Yes" << endl;
    else cout << "No" << endl;
}
  
int32_t main() {
 
    FAST;

    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    
    Panda();

    return 0; 
} 