#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int cnt=0;
  int g[101];
  int gn[101];  
  int x=1;
  gn[0]=x;
  int l=1;
  while(1){
    x*=2;
    if(n<x)break;
    gn[l]=x;
    l++;
  }
  int m=l;
  for(int i=m-1,j=0;i>=0;i--,j++){
    g[j]=gn[i];
  }
  for(int i=0;i<m;i++){
    //insert
    for(int j=g[i];j<n;j++){
      int v=a[j];
      int k=j-g[i];
      while(k>=0&&a[k]>v){
	a[k+g[i]]=a[k];
	k-=g[i];
	cnt++;
      }
      a[k+g[i]]=v;
    }
  }
  cout << m << endl;
  for(int i=0;i<m;i++){
    cout << g[i];
    if(i+1!=m)cout << " ";
  }
  cout << endl;
  cout << cnt<<endl;
  for(int i=0;i<n;i++){
    cout << a[i] << endl;
  }
  
  return 0;
}