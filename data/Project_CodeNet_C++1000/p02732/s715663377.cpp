#include <bits/stdc++.h>
using namespace std;
#define int long long int 

void solve(int arr[],int n){

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    int all=0;
    for(auto x:mp){
        all+=((x.second)*(x.second-1)/2);
    }
    
    int ans[n];
    for(int i=0;i<n;i++){

        ans[i]=all-(mp[arr[i]]-1);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}

int32_t main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    solve(arr,n);
    return 0;
}
