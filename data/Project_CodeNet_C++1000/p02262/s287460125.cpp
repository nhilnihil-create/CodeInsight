#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
vector<int> a;
void insertionsort(vector<int> &a,int n,int g){
  int v,i,j,k;
  for(i=g;i<n;i++){
    v=a[i];
    j=i-g;
    while(j>=0&&a[j]>v){
      a[j+g]=a[j];
      j=j-g;
      cnt++;
    }
    a[j+g]=v;
  }
  //  cout<<"insert:"<<&a<<endl;
}
vector<int> shellsort(vector<int> &a,int n){
  cnt = 0;
  int m,i;
  vector<int>g;
  for(i=1;i<n+1;i=i*3+1){
    g.push_back(i);
    //cout<<g[i]<<endl;
  }
  m=g.size();
  for(int i=m-1;i>=0;i--){
    insertionsort(a,n,g[i]);
  }
  //cout<<"@"<<m<<endl;
  // cout<<"shell:"<<&a<<endl;
  return g;
}

int main(){
  int m,n,tmp,i;
  vector<int>a;
  vector<int>g;
  cin>>n;
  for(i=0;i<n; i++){
    cin>>tmp;
    a.push_back(tmp);
  }
  //cout<<"main:"<<&a<<endl;
  g=shellsort(a,n);
  m=g.size(); 
  cout<<m<<endl;
  if(m>1){
    for(i=m-1;i>0;i--){
      cout<<g[i]<<" ";
    }
  }
  //cout<<"finished:"<<i<<endl;
  cout<<g[0]<<endl;
  cout<<cnt<<endl;
  for(i=0;i<n;i++)cout<<a[i]<<endl;
 
  return 0;
}

