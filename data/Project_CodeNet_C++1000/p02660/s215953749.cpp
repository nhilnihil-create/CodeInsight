#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    long long n;
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }
    long long a,count=0,i;
    a=sqrt(n)+1;
    map<int,int> mp;
    for(i=2;i<=a;i++){
        while(n%i==0){
            n/=i;
            mp[i]++;
            a=sqrt(n)+1;
        }
    }
    if(n!=1){
        mp[n]++;
    }
    // for(auto a:mp){
    //     cout<<a.first<<" "<<a.second<<endl;
    // }
    int ans=0;
    for(auto a:mp){
        for(int i=1;a.second-i>=0;i++){
            a.second-=i;
            ans++;
        }
    }
    cout<<ans;
}
