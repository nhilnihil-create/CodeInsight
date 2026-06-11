#include <bits/stdc++.h>
#define int long long

#define mp make_pair
#define pb push_back
#define mod (int)1e9+7
using namespace std;

signed main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1[n];
    int cnt2[n];
    int cnt3[n];
    memset(cnt1,0,sizeof cnt1);
    memset(cnt2,0,sizeof cnt2);
    memset(cnt3,0,sizeof cnt3);
    cnt1[0] = (s[0] == 'R' ? 1 : 0);
    cnt2[0] = (s[0] == 'G' ? 1 : 0);
    cnt3[0] = (s[0] == 'B' ? 1 : 0);
    for(int i = 1;i<n;i++){
        cnt1[i] = cnt1[i-1];
        cnt2[i] = cnt2[i-1];
        cnt3[i] = cnt3[i-1];
        cnt1[i] += (s[i] == 'R' ? 1 : 0);
        cnt2[i] += (s[i] == 'G' ? 1 : 0);
        cnt3[i] += (s[i] == 'B' ? 1 : 0);
    }
    int res = 0;
    for(int i =0;i<n;i++){
        for(int z = i+1;z<n;z++){
            int x = z+z-i;
            if(s[i] == s[z]) continue;
            set<char> ccc;
            ccc.insert('R');
            ccc.insert('G');
            ccc.insert('B');
            ccc.erase(s[i]);
            ccc.erase(s[z]);
            auto it = *ccc.begin();
            int cc = 4;
            if(it == 'R') cc = 0;
            if(it == 'G') cc = 1;
            if(it == 'B') cc = 2;
            if(cc == 0){
                res += cnt1[n-1]-cnt1[z];
                if(x >= n) continue;
                if(s[x] != s[i] && s[i] != s[z] && s[z] != s[x]) res--;
            }
            if(cc == 1){
                res += cnt2[n-1]-cnt2[z];
                if(x >= n) continue;
                if(s[x] != s[i] && s[i] != s[z] && s[z] != s[x]) res--;
            }
            if(cc == 2){
                res += cnt3[n-1]-cnt3[z];
                if(x >= n) continue;
                if(s[x] != s[i] && s[i] != s[z] && s[z] != s[x]) res--;
            }
        }
    }
    cout << res;
}
