#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i];
    }
    string x;
    cin >> x;
    ll ans = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(flag){
            ans += t[i];
        }
        if(s[i] == x) flag = true;
    }
    cout << ans << endl;

    return 0;
}