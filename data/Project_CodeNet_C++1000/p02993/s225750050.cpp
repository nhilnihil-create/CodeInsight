#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

 

int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    bool flag=false;
    for(int i=0;i<s.size()-1;i++)
    {
    	if(s[i]==s[i+1])
    		flag=true;
    }
    if(flag)
    {
    	cout<<"Bad"<<endl;
    }
    else
    {
    	cout<<"Good"<<endl;
    }

	return 0;

}