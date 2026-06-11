#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int cnt=0;
  for(int i=1;i<=n;i++) {
    int a;
    cin>>a;

    if(i%2==1&&a%2==1) {
      cnt++;
    }
  }
  cout<<cnt<<endl;
}
