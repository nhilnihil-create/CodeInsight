#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    vector<ll> t(n);

    for(int i=0;i<n;i++){
        cin >> s[i] >> t[i];
    }

    string x;
    cin >> x;

    ll ans = 0;

    for(int i=0;i<n;i++){
        ans += t[i];
        if(s[i] == x){
            ans = 0;
        }
    }

    cout << ans << endl;
    return 0;
}