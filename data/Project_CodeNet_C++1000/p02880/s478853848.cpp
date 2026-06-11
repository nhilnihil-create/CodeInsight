#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  bool t=false;
  for(int i=1; i<10; i++){
    if(n%i==0){
        int a=n/i;
        if(a<=9){t=true; break;}
    }
  }
  if(t){cout<<"Yes";}
  else{cout<<"No";}
  return 0;
}