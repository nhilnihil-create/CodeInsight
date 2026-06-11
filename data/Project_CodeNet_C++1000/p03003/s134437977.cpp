#include<bits/stdc++.h>
using namespace std;

int main(){
  int M=1e9+7,n,m;
  int64_t ans=1; //長さ0の部分列の分はあらかじめ足しておく
  cin>> n >> m;
  vector<int> s(n),t(m);
  unordered_map<int,set<int>> ms;
  for (int i=0; i<n; i++) cin>> s[i];
  for (int i=0; i<m; i++) cin>> t[i];
  
  for (int i=0; i<n; i++) ms[s[i]].insert(i);
  vector<int> a(n);
  for (int i=0; i<m; i++){
    int k=0,num=0,var;
    for (int j: ms[t[i]]){
      while (k<j){
        num+=a[k]; num%=M;
        k++;
      }
      var=num;
      num+=a[j]; num%=M;
      a[j]+=var+1;a[j]%=M;
      k++;
    }
  }
  for (int i: a){ ans+=i; ans%=M;}
  cout<< ans <<endl;
}