#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a (n);
  map<int,int64_t> kaz;
  for(int i = 0;i < n;i++){
    cin >> a.at(i);
    kaz[a.at(i)]++;
  }
  int64_t al = 0;
  for(auto x:kaz){
    al+=x.second*(x.second-1);
  }
  //cout << al << endl;
  for(int i = 0;i < n;i++){
    cout << (al - kaz[a.at(i)]*(kaz[a.at(i)]-1) + (kaz[a.at(i)]-1)*(kaz[a.at(i)]-2))/2 << endl;
  }
  return 0;
}