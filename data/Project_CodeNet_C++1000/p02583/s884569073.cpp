#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }        
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i+1; j < n; j++)
            {
                for (size_t k = j+1; k < n; k++)
                {
                    if(a[i] != a[j] && a[j] != a[k] && a[i] != a[k] && a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[i] + a[k] > a[j]){
                        // cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                        ans++;
                    }
                }
                
            }
            
        }

        cout<<ans<<endl;
        
    }
    return 0;
}