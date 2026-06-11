#include<bits/stdc++.h>

using namespace std;
int main()
{
   int a,b;
   cin>>a>>b;
   string s1=string(b,'0'+a);
   string s2=string(a,'0'+b);
    if(s1.size()!=s2.size())
    {
        if(s1.size()>s2.size()) cout<<s1;
        else cout<<s2;
    }
    else{
        if(s1>s2) cout<<s1;
        else cout<<s2;
    }
}
