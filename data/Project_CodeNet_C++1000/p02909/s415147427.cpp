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
    string s; cin >> s;
    if(s == "Sunny"){
        cout << "Cloudy\n";
    }else if(s == "Cloudy"){
        cout << "Rainy\n";
    }else{
        cout << "Sunny\n";
    }
    return 0;
}