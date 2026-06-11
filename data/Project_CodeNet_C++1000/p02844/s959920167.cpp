#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0;i < 1000;i++){
        string t = "";
        if(i < 10)t += '0';
        if(i < 100)t += '0';
        t += to_string(i);
        int cnt = 0;
        rep(j,n){
            if(s[j] == t[cnt])cnt++;
            if(cnt == 3){
                ans++;
                //cout << t << endl;
                break;
                }
        }
    }
    cout << ans << endl;
    return 0;
}