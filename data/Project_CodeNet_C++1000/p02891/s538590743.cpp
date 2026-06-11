#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s; cin >> s;
    int k; cin >> k;

    char tmp;
    int cnt = 1;
    int n = s.length();
    ll change = 0;
    ll a=0, b=0;
    for(int i=0; i<n; i++){
        if(i==0) tmp = s.at(i);
        else{
            if(s[i] == tmp){
                cnt++;
                if(s[i]==s[0] && i==n-1) b = cnt;
                if(i==n-1){
                    change += cnt/2;
                }
            }else{
                if(s[i-1]==s[0]) a = cnt;
                change += cnt/2;
                tmp = s[i]; cnt=1;
            }
        }
    }
    ll ans = change * k;
    if(s[0] == s[n-1]){
        ans -= (a/2 + b/2 - (a+b)/2) * (k-1);
    }
    if(s == string(s.size(),s[0])) {
        cout << s.size() * k / 2 << endl;
        return 0;
    }else
        cout << ans << endl;
    return 0;

}