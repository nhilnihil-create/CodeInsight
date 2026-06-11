#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++)cin>>h[i];
    long long ans=0;
    sort(h,h+n);
    if(n>k){
        for(int i=0;i<n-k;i++){
            ans+=h[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}