#include<bits/stdc++.h>  
using namespace std;
 
#define mod 1e9+7
 
typedef long long ll;
 
int ans=INT_MAX;
bool visited=false;

 
int main()
{
    string s="";
    cin>>s;

    if(s.size()%2){
    	cout<<"No";
    	return 0;
    }

    for(int i=0;i<s.size();i+=2){
    	if(s[i]!='h' || s[i+1]!='i')
    	{
    		cout<<"No";
    		return 0;
    	}
    }

	cout<<"Yes";

    return 0;
}
     