#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]+n<=90)
        {
            s[i]=s[i]+n;
        }
        else{
            s[i]=(n-(90-s[i]))+64;
        }
        cout<<s[i];


    }
    return 0;

}
