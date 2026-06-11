#include<bits/stdc++.h>
using namespace std;

int kai(int n){
  if(n<=1)
    return 1;
  else
    return n*kai(n-1);
}

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  for(int i=0;i<n;i++)
    cin >> b.at(i);
  int an=0,bn=0,x;
  set<int>num;
  for(int i=1;i<=n;i++)
    num.insert(i);
  int k=1;
  for(int i=0;i<n;i++){
    int j=0;
    for(auto x:num){
      if(x==a.at(i)){
        break;
      }
      j++;
    }
    num.erase(a.at(i));
    an=an+kai(n-k)*j;
    k++;
  }
  num.clear();
  for(int i=1;i<=n;i++)
    num.insert(i);
  k=1;
  for(int i=0;i<n;i++){
    int j=0;
    for(auto x:num){
      if(x==b.at(i)){
        break;
      }
      j++;
    }
    num.erase(b.at(i));
    bn=bn+kai(n-k)*j;
    k++;
  }
  cout << abs( an - bn ) << endl;
  return 0;
}