#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N, M; string S;
    cin >> N >> M >> S;
    reverse(S.begin(), S.end());

    vector<int> ans;

    int cur = 0;
    while(cur != N){
        bool stop = true;
        for(int i=M; i>=1; i--){
            if(S[cur+i] == '0'){
                ans.push_back(i);
                cur += i;
                stop = false;
                break;
            }
        }

        if(stop) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    reverse(ans.begin(), ans.end());
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
}