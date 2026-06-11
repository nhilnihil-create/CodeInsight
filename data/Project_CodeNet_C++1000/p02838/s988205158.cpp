#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long int cou[2][70];
int main(){
    long long int N;
    cin>>N;
    for(long long int i=0;i<N;i++){
        long long int pa;
        cin>>pa;
        for(long long int i=0;i<61;i++){
            cou[pa%2][i]++;
            pa/=2;
        }
    }
    long long int ans=0;
    long long int rui2=1;
    for(long long int i=0;i<61;i++){
        ans+=((((cou[0][i]*cou[1][i])%1000000007)*rui2)%1000000007);
        ans%=1000000007;
        rui2*=2;
        rui2%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
