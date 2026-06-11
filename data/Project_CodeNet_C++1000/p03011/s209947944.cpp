#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  vector<int >p;
  p.push_back(a+b);
  p.push_back(a+c);
  p.push_back(c+b);
  sort(p.begin(),p.end());
       cout<<p[0];
       return 0;
       }
