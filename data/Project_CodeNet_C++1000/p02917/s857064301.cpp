#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    vector<int> v, ans;
    for(int i = 0, x; i < n - 1; ++i){
        cin >> x;
        v.push_back(x);
    }   
    v.push_back(INT_MAX);
    ans.push_back(v[0]);
    for(int i = 0; i < v.size() - 1; ++i){
        ans.push_back(min(v[i], v[i + 1]));
    }
    int a = 0;
    for(auto &x : ans){
        a += x;
    }
    return cout << a << '\n', 0;
}