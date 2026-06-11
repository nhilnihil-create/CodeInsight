#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,m,k;
  cin >> n;
  vector<int> a(n);
  m=0,k=0;
  for(i=0;i<n;i++){
    cin >> a.at(i);
    if(a.at(i)>m){
      m=a.at(i);
      k=i;
    }
  }
  
  int m2=0;
  for(i=0;i<n;i++){
    if(i!=k){
      m2=max(m2,a.at(i));
    }
  }
  
  for(i=0;i<n;i++){
    if(i!=k){
      cout << m << endl;
    }else{
      cout << m2 << endl;
    }
  }
}