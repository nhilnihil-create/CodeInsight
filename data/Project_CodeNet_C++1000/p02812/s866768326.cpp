#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int n,cnt=0;
  cin>>n>>s;
  for(int a=0; a<n; a++)
  {
    
	if(s[a]=='A'&& s[a+1]=='B'&& s[a+2]=='C'){
      cnt++;
    }
  }
  
  cout<<cnt<<endl;
  
}
      