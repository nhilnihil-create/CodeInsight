#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long n,ans=0;
    cin >>n;
    vector<int>x(n);
    
    for(int i=0;i<n;i++){
        cin >> x[i];
        ans+=pow(x[i],2);
    }
    
    for(int i=1;i<=100;i++){
        long long res=0;
        for(int j=0;j<n;j++){
            res+=pow(x[j]-i,2);
        }
        
        ans=min(ans,res);
    }
    
    cout<<ans<<endl;
}
