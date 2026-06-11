#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const long long int N=2e6+30;
int main(){
    string s;
    cin >> s;
    if (s[s.size()-1] == 's') cout << s << "es" << endl;
    else cout << s << 's' << endl;
}

