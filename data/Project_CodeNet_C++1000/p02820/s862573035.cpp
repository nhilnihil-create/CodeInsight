#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long n,k,i,r,s,p,total=0;
    string str;
    cin>>n>>k;
    cin>>r>>s>>p;
    cin>>str;
    for(i=0;i<k;i++)
    {
        if(str[i]=='r')
        {
            total+=p;
        }
        else if(str[i]=='s')
        {
            total+=r;
        }
        else if(str[i]=='p')
        {
            total+=s;
        }
    }
    for(i=k;i<str.size();i++)
    {
        if(str[i]==str[i-k])
        {
            str[i]='x';
            total+=0;
        }
        else
        {
            if(str[i]=='r')
            {
                total+=p;
            }
            else if(str[i]=='s')
            {
                total+=r;
            }
            else if(str[i]=='p')
            {
                total+=s;
            }
        }
    }
    cout<<total<<endl;
    return 0;
}