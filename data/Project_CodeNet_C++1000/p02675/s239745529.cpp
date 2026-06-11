#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
  	cin>>s;
  	int n = s.length();
  	
  	if(s[n-1] == '2'|| s[n-1] == '4'||s[n-1] == '5'||s[n-1] == '7'||s[n-1] == '9')
    { 
      cout<<"hon";
      return 0;
    }
  	
  	if(s[n-1] == '0'||s[n-1] == '1'||s[n-1] == '6'||s[n-1] == '8')
    {
      cout<<"pon";
      return 0;
    }
  	if(s[n-1] == '3')
      cout<<"bon";
  
  	return 0;
}
