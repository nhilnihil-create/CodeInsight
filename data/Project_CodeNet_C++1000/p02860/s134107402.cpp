#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2!=0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    int flag=1;
    int m=n/2;
    for(int i=0; i<n/2; i++)
    {
        if(s[i]!=s[m])
        {
            flag=0;break;
        }
        m++;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
