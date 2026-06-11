#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<pair<long long,long long>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i+1;
    }
    sort(A.begin(),A.end());
    /*
    for(auto p:A){
        cout<<"<"<<p.first<<","<<p.second<<"> ";
    }
    //*/

    //*
    vector<vector<long long>> dp(N+1,vector<long long>(N+1,0));
    int pt=A.size()-1;
    for(int i=1;i<=N;i++){
        //cout<<A[pt].first<< " "<<A[pt].second<<endl;
        for(int j=0;j<=i;j++){
            //cout<<j<<" "<<i-j<<endl;
            if(j==0){
                dp[j][i-j]=dp[j][i-j-1]+A[pt].first*abs(N+1-i+j-A[pt].second);
            }else if(i-j==0){
                dp[j][i-j]=dp[j-1][i-j]+A[pt].first*abs(j-A[pt].second);
            }else{
                dp[j][i-j]=max(dp[j][i-j-1]+A[pt].first*abs(N+1-i+j-A[pt].second),dp[j-1][i-j]+A[pt].first*abs(j-A[pt].second));
            }
        }
        pt--;
    }
    /*
    for(int i=0;i<=N;i++){
        for(auto p:dp[i]){
            cout<<p<<" ";
        }
        cout<<endl;
    }
    //*/
    long long ans=0;
    for(int i=0;i<=N;i++){
        if(ans<dp[i][N-i]){
            ans=dp[i][N-i];
        }
    }
    cout<<ans<<endl;
    //*/


    return 0;
}