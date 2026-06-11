#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <ctime>

using namespace std;
int main()
{

	

	string s; cin>>s; int max=0;
	for(int i=0; i<=(int)s.size()-1; ++i)
	{
		        int sum=0;
			    if(s[i]=='R'){
			    	int j=i;
			    	while(s[j]=='R')
			    	{
			    		sum++;
			    		j++;
			    	}
			    	if(sum>max) max=sum;

			    }

			}cout<<max<<endl;







  	return 0;
  }
