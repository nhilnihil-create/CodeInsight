#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s , ss;
    cin >> s >> ss;
    int c = 0;
    for(int i = 0 ; i < 3 ; i++){
        c += (s[i] == ss[i]);
    }
    cout << c << endl;

    return 0;
}
