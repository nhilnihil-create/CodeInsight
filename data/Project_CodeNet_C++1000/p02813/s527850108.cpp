#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

signed main(){
    io();
    int n; cin >> n;
    string s1, s2;
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        s1 += c;
    }
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        s2 += c;
    }
    string ref = s1;
    sort(all(ref));
    int a = 0;
    int b = 0;
    int i = 0;
    do{
        ++i;
        if(s1 == ref) a = i;
        if(s2 == ref) b = i;
    }while(next_permutation(all(ref)));
    cout << abs(a - b) << '\n'; 
    return 0;
}