#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n],rev[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
        rev[i] = arr[i];
    }
    sort(rev,rev+n,greater<int>());
    int first = rev[0];
    for (int i=0;i<n;++i){
        if (arr[i]!=first){
            cout<<first;
        }
        else{
            cout<<rev[1];
        }
        cout<<"\n";
    }
}