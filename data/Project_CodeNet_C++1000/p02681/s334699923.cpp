 #include<bits/stdc++.h>
using namespace std;
int main()
{ 
  string a,b;
  cin>>a>>b;
  b.pop_back();
  if(a.compare(b)==0)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
} 