#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n;
    cin >> n;
    vector<char> name;
    name.push_back('z');
    for(char i = 'a'; i <= 'y'; ++i){
        name.push_back(i);
    }
    vector<char> ans;
    while(n >= 1){
        int i = n % 26;
        ans.push_back(name[i]);
        // cout << i << " " << n << endl;
        n /= 26;
        if(i == 0) --n;
    }
    reverse(ans.begin(), ans.end());
    rep(i,ans.size()) cout << ans[i];
    cout << endl;
    return 0;
}