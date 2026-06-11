#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define sqr(x) (x)*(x)
using namespace std;

int main(){
#ifdef LOCAL
    freopen("inp.txt", "r", stdin );
    freopen("ans.txt", "w", stdout);
#endif
    string t = "ABC";
    int n; cin >> n;
    string s; cin >> s;
    int c = 0;
    for(int i=0; i<=n-3; i++){
    	if(s.substr(i,3)==t) c++;
    }
    cout << c << '\n';
}
