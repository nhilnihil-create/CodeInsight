#include<bits/stdc++.h>
using namespace std;
int main()
{
  	string s;
  	cin>>s;
   
  	bool isok = true;
  	if(s.size()%2 != 0)
      cout<<"No";
  	else
    {
      	for(int i=0; i<s.size()-1; i=i+2) {
      		if( s[i] =='h' && s[i+1] =='i' ) {
              continue;
      		}
           else {
             isok = false;
           		break;
           }
    	}
    	if(isok)
          cout<<"Yes";
      	else
          cout<<"No";
    }
  
  	
	return 0;
}