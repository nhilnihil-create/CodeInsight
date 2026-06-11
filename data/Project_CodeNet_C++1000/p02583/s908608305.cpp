#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l[n];
    for(int i = 0; i<n; i++){
        cin >> l[i];
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(l[i]+l[j]>l[k] && l[i]+l[k] > l[j] && l[j]+l[k] > l[i] && l[i]!=l[j] && l[j]!=l[k] && l[i]!=l[k]){
                    ans++;    
                }
            }
        }
    }
    
    cout << ans << "\n";
}
