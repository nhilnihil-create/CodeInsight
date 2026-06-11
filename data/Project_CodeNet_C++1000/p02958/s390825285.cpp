#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int temp[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
        temp[i]=arr[i];
    }
    vector<int>v;
    sort(temp,temp+n);
    for (int i=0;i<n;++i){
        if (arr[i]!=temp[i]){
            v.push_back(i);
        }
    }
    if (v.size()>2 || v.size()==1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    
}