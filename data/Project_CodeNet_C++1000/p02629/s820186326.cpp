#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll n;
    cin >> n;
    string ans;
    while(n){
        n--;
        ans.push_back((char)('a'+n%26));
        n/=26;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}