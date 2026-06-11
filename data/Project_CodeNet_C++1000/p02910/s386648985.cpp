#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
    	if(i%2==0){
    		char tap=s.at(i);
    		if(tap=='L'){
    			cout<<"No\n";
    			return 0;
			}
		}
		else{
    		char tap=s.at(i);
    		if(tap=='R'){
    			cout<<"No\n";
    			return 0;
			}
		}
	}
	cout<<"Yes\n";
	return 0;
}