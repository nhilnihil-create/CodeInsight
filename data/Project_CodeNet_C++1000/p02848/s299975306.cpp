#include<iostream>
#include<string>
using namespace std;
int main()
{
    long long n,i;
    string s;
    cin>>n>>s;
    for(i=0;i<s.size();i++)
    {
        s[i]=s[i]+n;
        if(s[i]>'Z')
        {
            s[i]-=n;
            s[i]-=(26-n);
        }
    }
    cout<<s<<endl;
    return 0;
}