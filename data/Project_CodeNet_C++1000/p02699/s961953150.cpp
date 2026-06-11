// Vivek Rai
// Blazer_007

#include<bits/stdc++.h>
using namespace std;

#define fastio    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl      '\n'

typedef long long int ll;
const int hell = 1e9 + 7 ;

signed main() {

    fastio

    int s , w;
    cin >> s >> w;

    if(w >= s)
    	cout << "unsafe";
    else
    	cout << "safe";

    return 0;
}