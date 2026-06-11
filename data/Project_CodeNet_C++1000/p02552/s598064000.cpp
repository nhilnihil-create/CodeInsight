#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  float x;
  cin>>x;
  int left = floor(x);
  int right = ceil(x);
  if(left==right&&right==1)
    cout<<0<<endl;
  else if(left==right&&right==0)
    cout<<1<<endl;
}

