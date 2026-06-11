#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;
    int k = n/2;

    string ret = "No";
    if(n%2==0 && s.substr(0,k)==s.substr(k,n)){
        ret = "Yes";
    }

    cout << ret << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}