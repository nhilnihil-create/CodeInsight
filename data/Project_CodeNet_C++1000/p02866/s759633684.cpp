#include<iostream>
#include<vector>
using namespace std;

int mod=998244353;

int main(){
    int n; 
    cin>>n;
    vector<int> c(100000,0);
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        if(i==0){
            if(d!=0){
                cout<<0<<endl;
                return 0;
            }
        }
        c[d]++;
    }

    long long ans=0;
    if(c[0]==1) ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c[i];j++){
            ans*=c[i-1];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}