#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef LOCAL_EXEC
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif // LOCAL_EXEC
    vector<long long int>vt;
    long long int i,n,j;
    cin>>n;
    long long int A[n+1];
    bool ok=true;
    vt.push_back(1);
    for(i=0;i<=n;i++){
        cin>>A[i];
        if(A[i]>vt[vt.size()-1])
            ok=false;
        if((vt[i]-A[i])*2<1e18)
        vt.push_back(max(0ll,(vt[i]-A[i])*2));
        else
            vt.push_back(1e18);
        }
        //for(i=0;i<vt.size();i++){
          //  cout<<vt[i]<<endl;
        //}
        //cout<<vt.size()<<endl;
        if(n==0&&A[0]!=1)
            ok=false;
        if(ok==false)
            cout<<-1;
        else{
            long long int sum=0,dp[n+1];
            //cout<<ok<<endl;
                    dp[n]=A[n];
                    for(i=n-1;i>=0;i--){
                        dp[i]=A[i]+dp[i+1];
                        //cout<<vt[i]<<" ";
                        dp[i]=min(vt[i],dp[i]);
                    }
            for(i=0;i<=n;i++){
                sum+=dp[i];
            }
            cout<<sum;
            }
    return 0;
}
