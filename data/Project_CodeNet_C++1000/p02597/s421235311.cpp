#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1e8;
    int size = s.size();
    int wcnt = 0;
    int rcnt = 0;
    rep(i,size){
        if(s.at(i) == 'W'){
            wcnt++;
        }
        else{
            rcnt++;
        }
    }
    wcnt = 0;
    ans = min(ans, max(0,rcnt));
    rep(i,size){
        if(s[i] == 'W'){
            wcnt++;
            ans = min(ans,max(wcnt,rcnt));
        }
        else{
            rcnt--;
            ans = min(ans,max(wcnt,rcnt));
        }
    }
    cout << ans << endl;
}