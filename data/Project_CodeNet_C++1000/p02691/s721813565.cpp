#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  map<int,int> b;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    b[i-a.at(i)]++;
  }
  int64_t c=0;
  for(int i=0;i<n;i++)
    c+=b[i+a.at(i)];
  cout<<c<<endl;
}