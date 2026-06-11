#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,flag=0;
    cin>>t;
bool ok,take;
    vector<int>v;
    for(int i=0;i<t;i++){
    cin>>n;
    v.push_back(n);
    }

ok=is_sorted(v.begin(),v.end());
if(ok){
    cout<<"YES"<<endl;
}
if(!ok){
for(int i=0;i<t;i++){
    for(int j=i+1;j<=t-1;j++){
        if(v[i]>v[j]){
            swap(v[i],v[j]);
     take=is_sorted(v.begin(),v.end());
    if(take){
        cout<<"YES"<<endl;
    flag++;
    break;
    }
        else{
            swap(v[i],v[j]);
        }
}

    }
}
}
if(flag==0&&!ok){
    cout<<"NO"<<endl;
}

}








