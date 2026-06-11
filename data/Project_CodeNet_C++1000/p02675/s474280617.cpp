#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N,mn;
  cin>>N;
  mn=N%10;
  if(mn==3) cout<<"bon";
  else if(mn<=1||mn==6||mn==8) cout<<"pon";
  else cout<<"hon";
}