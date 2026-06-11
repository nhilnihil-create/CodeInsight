#include <bits/stdc++.h>
using namespace std;
#define INFTY powl(2,60)

vector<vector<long long>> m(101,vector<long long>(101));
vector<int> p(101);

long long matrixChainMultiplication(int n){
    for(int i=1;i<n+1;i++){
        m[i][i]=0;
    }
    for(int l=1;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l;
            m[i][j]=INFTY;
            for(int k=i;k<j;k++){
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    return m[1][n];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i]>>p[i+1];
    }
    cout<<matrixChainMultiplication(n)<<endl;
}
