#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x[105],ans=100000000;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=100;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=abs(i-x[j])*abs(i-x[j]);
        }
        if(ans>sum){
            ans=sum;
        }
    }
    cout<<ans<<endl;
    return(0);
}
