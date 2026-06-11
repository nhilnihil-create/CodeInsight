#include <iostream>
using namespace std;
 
int main()
{
	string wheather;
  	cin>>wheather;
  	int cnt=0; 
  	int maxcnt=0;
  	
  	for(int loop=0;loop<3;loop++)
    {
      	if(wheather[loop]=='R')
        {
          	cnt++;
          if(maxcnt<=cnt)
            maxcnt=cnt;
        }
      	else
          cnt=0;
    }
  	cout<<maxcnt<<endl;
 	return 0;
}