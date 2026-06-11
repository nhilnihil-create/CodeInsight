#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  string s;
  cin>>s;
  if(s.length()==6 && (s[2]==s[3]) && (s[4]==s[5])){
  	cout<<"Yes"<<endl;
  }else{
  	cout<<"No"<<endl;
  }

return 0;
}

