#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> ans(n, 1);
    for(int i = 0; i < n; ++i){
        int cur = 1, aux = i;
        if(s[i] == 'R'){
            while(s[aux + 1] == 'R'){
                ++aux;
                ++cur;
            }
            if(cur > 1){
                if(cur & 1){
                    ++ans[cur + i - 1];
                }else{
                    ++ans[cur + i];
                }
            }
        }else{
            while(s[aux - 1] == 'L'){
                --aux;
                ++cur;
            }
            if(cur > 1){
                if(cur & 1){
                    ++ans[i - cur + 1];
                }else{
                    ++ans[i - cur];
                }
            }
        }
        if(cur > 1) --ans[i];
        //cout << i << ' ' << s[i] << " mov: " << cur << '\n';
    }
    for(auto &i: ans){
        cout << i << ' ';
    }
    return 0;
}