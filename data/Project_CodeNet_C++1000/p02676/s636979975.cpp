#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,i,l;
    string s;
    cin>>k>>s;
    l=s.size();
    if(l<=k)
        cout<<s<<endl;
    else
    {
        for(i=0;i<k;i++)
        {
            cout<<s[i];
        }
        cout<<"..."<<endl;
    }
	return 0;
}

