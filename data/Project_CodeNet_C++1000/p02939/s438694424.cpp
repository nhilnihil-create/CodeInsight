#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    string old,now;
    rep(i,s.size()){
        now += s[i];
        if(old == now)continue;
        old = now;
        now = "";
        ans++;
    }
    cout << ans << endl;
    return 0;
}
