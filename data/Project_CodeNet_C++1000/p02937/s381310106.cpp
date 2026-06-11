#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
   string s,t;
   cin>>s>>t;
   vector<int> alpha[26];
   for(int i=0;i<s.length();i++)
   	alpha[s[i]-'a'].push_back(i);
   	int pos=-2,cnt=0;
   	for(int j=0;j<t.length();j++)
   {
   	std::vector<int>::iterator cpos;
	   cpos=std::lower_bound(alpha[t[j]-'a'].begin(), alpha[t[j]-'a'].end(),pos+1);
	   if(cpos==alpha[t[j]-'a'].end())
	   {
	   	if(alpha[t[j]-'a'].size()==0)
	   	{cout<<-1;
	   	return 0;
		}
		else
		{pos=alpha[t[j]-'a'][0];
		++cnt;
		}
		}
		else
		pos=*cpos; 
   }
   cout<<cnt*s.length()+pos+1;
    return 0;
}