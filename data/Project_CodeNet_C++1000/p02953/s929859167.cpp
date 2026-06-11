#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,i,j;
  string s="Yes";
  cin>>n;
  vector<int> h(n);
  for(i=0;i<n;i++) cin>>h.at(i);
  for(i=0;i<n-1;i++){
    if(h.at(i+1)-h.at(i)<-1) {s="No"; break;}
    else if(h.at(i+1)-h.at(i)==-1 && i<n-2){
      for(j=i+2;j<n;j++){
        if(h.at(j)<h.at(i+1)) {s="No"; break;}
        else if(h.at(j)>=h.at(i)) break;
      }
      if(j==n || s=="No") break;
      else i=j-1;
    }
  }
  cout<<s<<endl;
}