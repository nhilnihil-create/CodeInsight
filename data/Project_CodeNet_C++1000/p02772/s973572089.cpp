#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  bool ok=1;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a%2==0){
      if(a%3!=0 && a%5!=0){
        ok=0;
      }
    }
  }
  if(ok)cout << "APPROVED\n";
  else cout << "DENIED\n";
}