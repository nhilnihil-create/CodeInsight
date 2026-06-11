#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i,f=0;
    cin>>s;
    for(i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            f=1;
            break;
        }
    }
    cout<<(f?"Bad":"Good")<<endl;
}
