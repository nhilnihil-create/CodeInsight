#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    string S;
    cin >> S;
    ll cnt = 0;
    vector<ll>ans(S.size(), 0);
    rep(rp, 0, 2){
        rep(j, 0, S.size()){
               if(S[j] == 'R')cnt++;
               else {
                   ans[j] += cnt/2;
                   ans[j-1] += (cnt+1)/2;
                   cnt=0;
               }
        }
        
        reverse(S.begin(), S.end());
        reverse(ans.begin(), ans.end());
        rep(i, 0, S.size()){
            if(S[i] == 'R')S[i]='L';
            else S[i]='R';
        }
    }
    rep(i, 0, S.size()){
        cout << ans[i] << " ";
    }
    return 0;
}
