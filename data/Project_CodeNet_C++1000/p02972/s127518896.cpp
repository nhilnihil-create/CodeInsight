#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<bool>yon(n+1,false);
    vector<ll>ans;
    ll ansc=0;
    for(int i=n;i>=1;i--){
        int temp=0;
        for(int j=i;j<=n;j+=i){
            if(yon[j]==true)temp+=1;
    
        }
        if(temp%2==a[i])yon[i]=false;
        else {
            yon[i]=true;
            ansc+=1;
        }
    }
    cout<<ansc<<endl;
    for(int i=1;i<=n;i++){
        if(yon[i]==true)cout<<i<<endl;
    }
    
}