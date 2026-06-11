#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i;
  cin >> n;
  vector<int> p(n);
  for(i=0;i<n;i++){
    cin >> p.at(i);
  }
  
  int s=0;
  for(i=1;i<n-1;i++){
    if((p.at(i-1)-p.at(i))*(p.at(i+1)-p.at(i))<0){
      s++;
    }
  }
  
  cout << s << endl;
}