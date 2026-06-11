#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long x=0;
    for(int i=0;i<n;i++){
        if(i%2) x -= a[i];
        else x += a[i];
    }
    vector<int> ans(n,0);
    ans[0]=x/2;
    for(int i=0;i<n-1;i++) ans[i+1]=a[i]-ans[i];

    for(auto t : ans) cout<<t*2<<endl;
}