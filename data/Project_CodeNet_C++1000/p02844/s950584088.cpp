#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(j,1000){
        string s2;
        if(j < 10)
            s2 = "00" + to_string(j);
        else if(j < 100)
            s2 = "0" + to_string(j);
        else
            s2 = to_string(j);
        
        
        int cnt = 0;
        rep(i,n){
            if(s[i] == s2[cnt]){
                cnt++;
                if(cnt == 3){
                    ans++;
                    continue;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}