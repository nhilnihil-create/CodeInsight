
#include <bits/stdc++.h>
using namespace std;

    int main() {
        
        int n,k;
        cin >> n >> k;
        int arr[n];
        
        for(int i=0; i<n; i++)
            cin >> arr[i];
            
            sort(arr, arr+n);
            int ans=0;
//            for(int i=0; i<n; i++){
                for(int j=0; j<k; j++){
                    ans+=arr[j];
                    
                }
//            }
        
        cout << ans <<' ';
        return 0;
        }