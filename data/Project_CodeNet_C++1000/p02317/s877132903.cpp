#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#define ll long long
#define inf  1999999999
#define pa pair<int,int>
using namespace std;

int nibun(int a[],int d,int l,int h){
//cout<<"l="<<l<<" h="<<h<<" ";

if(h-l<=1 && a[h]>d) return l;
else if(h-l<=1) return h;
else{
int m=(l+h)/2;
if(a[m]>=d) nibun(a,d,l,m-1);
else nibun(a,d,m,h);

}
}


int main(){
int n,w;
int a[100010];
int dp[100010];
cin>>n;
for(int i=0;i<n+1;i++)dp[i]=inf;
dp[0]=-1;
for(int i=0;i<n;i++) cin>>a[i];
dp[1]=a[0];
int length=1;
for(int i=1;i<n;i++){
int k=nibun(dp,a[i],0,n+1);
//cout<<k<<endl;
if(dp[k]<a[i]) dp[k+1]=a[i];
if(dp[length+1]!=inf) length++;
//for(int b=0;b<n+1;b++) cout<<dp[b]<<" ";
//cout<<endl;
}

cout<<length<<endl;
return 0;
}