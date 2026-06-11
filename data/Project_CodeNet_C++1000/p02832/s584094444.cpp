#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  int cnt=0;
  for(int i=0;i<n;i++){
    if(a.at(i)==(cnt+1)){
      cnt++;
    }
  }
  if(cnt==0){
    cout<<-1;
  }else{
    cout<<n-cnt;
  }
}