#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x,y;
  cin>>x>>y;
  if(y%2==1){cout<<"No";}
  else{
    y=y/2;
    if(y-x<0){cout<<"No";}
    else{
        if(2*x-y>=0){cout<<"Yes";}
        else{cout<<"No";}
    }
  }
    return 0;
}