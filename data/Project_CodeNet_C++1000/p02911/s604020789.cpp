#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int arr[n+1];
    for (int i=1;i<=n;++i){
        arr[i] = k-q;
    }
    for (int i=0;i<q;++i){
        int x;
        cin>>x;
        arr[x]++;
    }
    for (int i=1;i<=n;++i){
        if (arr[i]>0){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
        cout<<"\n";
    }
}