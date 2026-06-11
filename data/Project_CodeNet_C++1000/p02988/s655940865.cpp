#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int cnt=0;
   for(int i=0;i<n-2;i++){
     if(vec[i]<vec[i+1]&&vec[i+1]<vec[i+2])cnt++;
     if(vec[i]>vec[i+1]&&vec[i+1]>vec[i+2])cnt++;
   }
  cout<<cnt<<endl;
}