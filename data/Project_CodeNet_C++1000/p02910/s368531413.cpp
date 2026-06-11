#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        if(i%2==0)
        {
           if(s[i]=='R'||s[i]=='D'||s[i]=='U')
                count++;
        }
        else
        {
            if(s[i]=='L'||s[i]=='D'||s[i]=='U')
                count++;
        }
    }
   if(count==s.length())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}
