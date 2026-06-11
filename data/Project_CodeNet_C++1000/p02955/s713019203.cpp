#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500],b[500];
int calc(int n, int t){
  int u=0,l=0,i;
  for(i=0;i<n;i++){
    b[i]=a[i]%t;
    l+=b[i];
  }
  sort(b,b+n,greater<int>());
  if(b[0]==0)
    return 0;
  for(i=0;i<n;i++){
    l-=b[i];
    u+=t-b[i];
    if(l==u)
      break;
  }
  return u;
}
int main()
{
  int n,k,s=0,m,t,u,i;
  cin >> n >> k;
  for(i=0;i<n;i++){
    cin >> a[i];
    s+=a[i];
  }
  m=(int)sqrt(s)+1;
  for(i=1;i<=m;i++){
    if(s%i>0)
      continue;
    t=s/i;
    if(t<i)
      break;
    u=calc(n,t);
    if(u<=k){
      cout << t << endl;
      return 0;
    }
  }
  for(i=m;i>0;i--){
    if(s%i>0||s/i<i)
      continue;
    u=calc(n,i);
    if(u<=k){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}