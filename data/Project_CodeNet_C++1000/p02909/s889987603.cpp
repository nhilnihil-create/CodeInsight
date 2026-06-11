#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

string S;
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S;
    if (S=="Sunny") cout << "Cloudy" << endl;
    else if (S=="Cloudy") cout << "Rainy" << endl;
    else cout << "Sunny" << endl;
}