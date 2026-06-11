#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  vector<int> a;
  vector<int> b;
  int n, tmp;
  cin >> n;
  rep(i,n){
    cin >> tmp;
    a.push_back(tmp);
    b.push_back(tmp);
  }
  sort(a.begin(),a.end());
  int pre=0;
  rep(i,n){
    if(a[i]!=b[i])
      pre++;
  }
  if(pre==0||pre==2){
    cout << "YES" << endl;
  } else{
    cout << "NO" << endl;
  }
  
}