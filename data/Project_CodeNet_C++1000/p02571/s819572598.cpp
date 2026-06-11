#include "bits/stdc++.h"
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2")

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

int main()
{
    ios_base::sync_with_stdio(0);
    string s,t; cin >> s >> t;
    int difmin = INT_MAX;
    int n = s.size();
    int m = t.size();
    for(int i{}; i<n-m+1; i++){
        int a = 0;
        for(int j{}; j<m; j++){
            if(s[i+j]!=t[j]) a++; 
        }
        difmin = min(a, difmin);
    }
    cout << difmin << "\n";
}
   