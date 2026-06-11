#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int i,l=s.size(),c=0;
    for(i=0;i<l;i++)
    {
        if(s[i]==t[i])
            c++;
    }
    if(c==l)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
	return 0;
}


