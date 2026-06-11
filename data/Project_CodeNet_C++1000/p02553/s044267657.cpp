#include<bits/stdc++.h>
using namespace std;
int main()
{ long long int a,b,c,d;
  cin>>a>>b>>c>>d;
 vector<long long int> v;
 v.push_back(a*c);
 v.push_back(a*d);
 v.push_back(b*c);
 v.push_back(b*d);
 long long int Y=*max_element(v.begin(),v.end());
 cout<<Y;

}
