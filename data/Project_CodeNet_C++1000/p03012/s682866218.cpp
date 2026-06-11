#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
int ans=100;
int sum1=0;
int sum2=0;
int n;cin>>n;
vector<int>w(n);
rep(i,n)cin>>w[i]; 
rep(i,n-1){
    sum1=0;sum2=0;
 for(int j=0;j<=i;j++){
     sum1=sum1+w[j];

 }
 for(int k=i+1;k<n;k++){
     sum2=sum2+w[k];
 }
 ans=min(ans,abs(sum1-sum2));
}
cout<<ans;



}