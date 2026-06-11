#include<bits/stdc++.h>
#include<string.h>

using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	
	t.erase(t.size()-1);
	if(s==t){
	    cout<<"Yes";
	}else{
	    cout<<"No";
	}
}
