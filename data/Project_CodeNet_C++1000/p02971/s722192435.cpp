#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  vector<int>b=a;
  sort(a.begin(),a.end(),greater());
  for(int i=0;i<n;i++){
    if(b.at(i)==a.at(0))
      cout << a.at(1) << endl;
    else
      cout << a.at(0) << endl;
  }
  return 0;
}