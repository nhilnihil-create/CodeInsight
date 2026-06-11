#include<iostream>
#include<string>
using namespace std;
int main()
{
    long long n,i;
    string s;
    cin>>n>>s;
    if(n%2!=0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        for(i=0;i<=(n/2)-1;i++)
        {
            if(s[i]!=s[i+(n/2)])
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}