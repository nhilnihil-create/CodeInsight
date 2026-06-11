#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    vector<int> vc;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        vc.push_back(a);
    }
    sort(vc.begin(), vc.end());
    vector<int> dp(1e6+1, 0);

    for(int i=0; i<n; i++){
        if(dp[vc[i]] != 0){
          dp[vc[i]] = 2;
          continue;
        }
        for(int j=vc[i]; j<1e6+1; j+=vc[i]){
            dp[j]++;
        }
    }

    for(int i=0; i<n; i++){
        if(dp[vc[i]] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
