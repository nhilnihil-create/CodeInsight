#include<bits/stdc++.h>
using namespace std;
int main(){
int n=0,h=0;
              cin>>n;
  vector<int> Ans(n+1,0);
               for(int i=1;i*i<=n;i++){
                for(int j=1;j*j<=n;j++){
                	for(int k=1;k*k<=n;k++){
                      h=i*i + j*j + k*k + i*j + i*k + j*k;
                      if(h<=n){
                      Ans[h]++;
                      }
                    }
                }
              }
              for(int i=1;i<=n;i++){
              cout<<Ans[i]<<'\n';
              }
              return 0;
            
}