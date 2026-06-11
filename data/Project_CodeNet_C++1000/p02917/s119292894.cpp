#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,sum=0;
  cin >> n;
  int a[n],b[n];
  for(int i=0;i<n;i++)a[i]=0;
  for(int i=0;i<n-1;i++)cin >> b[i];
  for(int i=0;i<n;i++){
    if(i==0)a[i]=b[i];
    else if(i==n-1)a[i]=b[i-1];
    else a[i]=min(b[i],b[i-1]);
  }
  sort(a,a+n);
  for(int i=0;i<n;i++)sum+=a[i];
  cout << sum << endl;
}