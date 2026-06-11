#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w,n;
    cin>>h>>w>>n;
    if (n<=min(h,w)){
        cout<<1;
        return 0;
    }
    int ans = max(h,w);
    if (n%ans==0){
        cout<<n/ans;
    }
    else{
        cout<<n/ans+1;
    }
}