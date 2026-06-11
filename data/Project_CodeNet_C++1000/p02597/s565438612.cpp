#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<char> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    int ans =0;
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]=='W'&&arr[j]=='R'){
            ans++;
            i++;
            j--;
        }else if(arr[i]=='R' &&arr[j]=='W'){
            i++;
            j--;
        }else if(arr[i]=='W'&&arr[j]=='W'){
            j--;
        }else if(arr[i]=='R' && arr[j]=='R')i++;
    }
    cout << ans << "\n";
    return 0;
}