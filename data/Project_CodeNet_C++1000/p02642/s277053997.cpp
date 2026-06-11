#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<bool> dp(a[n-1]+1,true);
    vector<int> b(a[n-1]+1);
    int ans=0;

    for(int i = 0; i < n; i++) {
        b[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
        
        if(dp[a[i]]==true){
            if(b[a[i]]==1){
                ans++;
            
                for(int j = a[i]; j < a[n-1]+1; j += a[i]) {
                    
                        dp[j]=false;
                    
                }
            }
            else if(b[a[i]]>1){
                for(int j = a[i]; j < a[n-1]+1; j += a[i]) {
                    
                        dp[j]=false;
                    
                }
                b[a[i]]=-1;
            }

        }
    }
    cout << ans << endl;

    return 0;
}

