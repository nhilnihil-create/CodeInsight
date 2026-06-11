#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N,D;
    cin>>N>>D;
    vector<vector<double>> X(N,vector<double>(D));
    rep(i,N){
        rep(j,D){
            cin>>X[i][j];
        }
    }
    int cnt=0;
    
    rep(i,N){
        
       for(int j=i+1;j<N;j++){
           int sum=0;
           rep(k,D){
              int d=abs(X[i][k]-X[j][k]);
              sum+=d*d;
           }
           rep(l,sum+1){
               if(l*l==sum){
                   cnt++;
               }
           }
          
       }
    }
    cout<<cnt<<endl;
}
