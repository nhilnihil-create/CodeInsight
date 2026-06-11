#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long n;
    cin>>n;
    
    vector<long long> A(n+1), B(n+1, 1e18);
    for(int i=0;i<n+1;i++) cin>>A[i];

    
    B[0]=1;
    
    if(A[0]>B[0]){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        B[i+1] = (B[i]-A[i])*2;
        if(B[i]<0){
            cout<<-1<<endl;
            return 0;
        }
        if(B[i]>=1e18) break;
    }
    
    if(A[n]>B[n]){
        cout<<-1<<endl;
        return 0;
    }
    
    long long ans,now;
    
    B[n]=ans=now=A[n];
    
    for(int i=n-1;i>=0;i--){
        now = min(now, B[i]-A[i])+A[i];
        ans += now;
    }
    
    cout<<ans<<endl;
}
