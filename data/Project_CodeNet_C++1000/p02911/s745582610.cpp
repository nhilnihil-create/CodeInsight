#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,q,k;
  cin >> n >> k >> q;
  map<int,int>toku;
  int a;
  for(int i=0;i<q;i++){
    cin >> a;
    toku[a-1]++;
  }
  for(int i=0;i<n;i++){
    if(toku[i]+k-q<=0){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }
  return 0;
}