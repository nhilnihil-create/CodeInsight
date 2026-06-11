#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    int n = s.size();
    int ans[n];
    rep(i,n) ans[i] = 0;
    rep(i,n - 1) {
        if(s[i]=='R' && s[i+1]=='L'){
            int j = i;
            while(s[j] == 'R'){
                if((i-j)%2==0) ans[i]++;
                else ans[i+1]++;
                j--;
            }
            int k = i+1;
            while(s[k] == 'L'){
                if((k-i-1)%2==1) ans[i]++;
                else ans[i+1]++;
                 k++;
            }
        }
    } 
    rep(i,n){
        if(i == 0) cout << ans[i];
        if(i) cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}