#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int hp = 0;
    if(s[0] == 'R' && s[1] == 'R') hp++;
    for(int i=1; i<n-1; i++){
        if(s[i] == 'R' && s[i+1] == 'R') hp++;
        if(s[i] == 'L' && s[i-1] == 'L') hp++;
    }
    if(s[n-1] == 'L' && s[n-2] == 'L') hp++;

    int now = s[0], ind = 0;
    int changed = 0;
    for(int i=0; i<k; i++){
        while(changed <= 1){
            ind++;
            if(ind >= n) break;
            if(s[ind] != now){
                changed++;
                now = s[ind];
            }
        }
        if(ind == n){
            if(changed == 1) hp++;
            break;
        }
        else{
            hp += 2;
        }
        changed = 0;
    }

    cout << hp << endl;

    return 0;
}