#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,N;
  cin>>H>>N;
  int sum=0;
  int a;
  for(int i=0; i<N; i++){
    cin>>a;
    sum+=a;
  }
  if(sum>=H) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}