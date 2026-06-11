#include <bits/stdc++.h>
using namespace std;
string s;
long long f[13];
int main(){
  cin>>s;
  f[0]=1;
  for(char c: s){
  	long long g[13];
    for(int i=0; i<13; i++) g[i]=0;
    int low=0, high=0;
    if(c=='?'){
    	low=0;
      	high=9;
    }
    else low=high=c-48;
    for(int j=low; j<=high; j++) for(int k=0; k<13; k++) g[(k*10+j)%13]+=f[k];
    for(int j=0; j<13; j++) f[j]=g[j]%1000000007;
  }
  cout<<f[5]<<'\n';
}