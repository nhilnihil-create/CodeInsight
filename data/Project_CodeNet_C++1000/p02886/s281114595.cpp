#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans = 0;
    cin >>n;
    int arr[n];
    for(int i = 0; i <n; ++i){
        cin >> arr[i];
    }
    for(int k = 0; k < n-1; ++k){
        for(int j =k+1; j < n; ++j ){
            ans+= (arr[k])*(arr[j]);
        }
    }
    cout<<ans; 

    return 0;
}