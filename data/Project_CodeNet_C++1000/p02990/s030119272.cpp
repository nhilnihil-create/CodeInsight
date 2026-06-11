#include<iostream>
using namespace std;

static const long long MOD=1e9+7;
long long C[2005][2005];

void COMB(){
    for(int i=0;i<2005;++i){
        C[i][0]=1;
        C[i][i]=1;
    }

    for(int i=2;i<2005;++i){
        for(int j=1;j<i;++j){
            C[i][j]=C[i-1][j-1]%MOD+C[i-1][j]%MOD;
            C[i][j]=C[i][j]%MOD;
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;

    COMB();

    for(int i=1;i<=k;++i){
        long long ans=C[n-k+1][i]*C[k-1][i-1]%MOD;
        cout<<ans<<endl;
    }
}