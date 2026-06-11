#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    int i;
    for(i=0;i<s.size();++i)
    {
        if(s[i]=='7')
        {
            cout<<"Yes"<<endl;
            break;
        }
    }
    if(i==s.size())
    {
        cout<<"No"<<endl;
    }
  	
   // cout<<ans<<endl;
	return 0;
}