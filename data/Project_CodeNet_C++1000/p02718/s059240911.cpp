#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr,arr+n,greater<int>());
        int req=(sum)/(4*m);
        if(req*(4*m)!=sum) req++;
        bool ok=1;
        for(int i=0;i<m;i++){
            if(arr[i]<req){
                ok=0;
                break;
            }
        }
        if(ok)cout << "Yes\n";
        else cout << "No\n";
    }
}
