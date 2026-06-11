#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    string s;
    cin>>n>>s;
    for(int i=0 ; i<s.size(); i++)
    {

        x=s[i]+n;
        if(x>90)
        s[i]=65-(91-x);
        else
            s[i]=s[i]+n;
    }
    cout<<s;
   return 0;
}

