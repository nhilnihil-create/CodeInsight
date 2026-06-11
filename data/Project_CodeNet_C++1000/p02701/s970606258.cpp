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

    int n;
    cin >> n;
    set<string> s;
    while(n--)
    {
    	string str;
    	cin >> str;
    	s.insert(str);
    }
    cout << s.size() << endl;

    return 0;
}