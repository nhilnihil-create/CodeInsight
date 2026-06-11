#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,c=0; cin>>n;
  for(int i=0;i<n;i++){cin>>a; if(a%2==0&&a%3&&a%5) c++;}
  cout<<(c?"DENIED":"APPROVED");
}