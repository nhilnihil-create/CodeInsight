#include <bits/stdc++.h>

using namespace std;

#define LL long int

const int MAX = 1e6;
const int MOD = 1e9+7;



int main(){
    int s;
    vector<int> ans(s + 1,0);
    cin >> s;

    ans[0] = 1;

    for(int i = 0; i <= s; ++i){
        if(i - 3 >= 0){
            ans[i] = ans[i - 1] + ans[i - 3];
            ans[i] %= MOD;
        }
    }

    cout << ans[s] << endl;

    return 0;
}