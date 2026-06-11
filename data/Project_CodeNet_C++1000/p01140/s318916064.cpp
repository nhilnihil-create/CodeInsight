#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int x,y,r;
  while(cin>>x>>y,x){
    r=max(x,y);
    int a[x+2]={0},b[y+2]={0},k,c[2000000],s=0;
    r(i,2000000)c[i]=-1;
    r(i,x){cin>>k;a[i+1]+=k;a[i+2]=a[i+1];}
    r(i,y){cin>>k;b[i+1]+=k;b[i+2]=b[i+1];}
    r(i,y+1)r(j,x+1)c[b[i]-a[j]+1000000]++;
    r(i,2000000)if(c[i]>0)for(int j=1;j<=c[i];j++)s+=j;
    cout<<s<<endl;
  }
}