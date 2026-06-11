#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,count=0,k1=0,k2=0;
  cin >>n;
  int p[n],q[n],a[n];
  for(int i=0;i<n;i++)a[i]=i+1;
  for(int i=0;i<n;i++)cin >> p[i];
  for(int i=0;i<n;i++)cin >> q[i];
  do{
    int cnt=0,cnt2=0;
    count++;
      for(int j=0;j<n;j++){
        if(a[j]==p[j])cnt++;
        if(a[j]==q[j])cnt2++;
      }
    if(cnt==n)k1=count;
      if(cnt2==n)k2=count;
  }while(next_permutation(a,a+n));
  cout << abs(k1-k2) << endl;
}