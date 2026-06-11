#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  int64_t c=1;
  vector<int> rgb(3,0);
  for(int i=0;i<n;i++){
    int p=0;
    int x=0;
    for(int j=0;j<3;j++){
      if(rgb.at(j)==a.at(i)){
        p=j;
        x++;
      }
    }
    c=c*x%1000000007;
    rgb.at(p)++;
  }
  cout<<c<<endl;
}