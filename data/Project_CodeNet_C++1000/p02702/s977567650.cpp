#include <bits/stdc++.h>

using namespace std;

signed main(){
    string s;
    cin >> s;
    int m[2019];
    memset(m,0,sizeof m);
    int c = s[0]-'0';
    m[c]++;
    int res = 0;
    for(int i = 1;i<s.size();i++){
        int x = s[i]-'0';
        int t[2019];
        memset(t,0,sizeof t);
        t[x] = 1;
        for(int z = 0;z<2019;z++){
            if(m[z] > 0){
                int cc = (z*10+x)%2019;
                if(cc%2019==0) res += m[z];
                t[cc%2019] += m[z];
            }
        }
        memset(m,0,sizeof m);
        for(int i= 0;i<2019;i++) m[i] = t[i];
    }
    cout << res;
}
