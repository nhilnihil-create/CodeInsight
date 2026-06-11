#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]+n)<=90)
            cout<<(char)(s[i]+n);
        else
            cout<<(char)((s[i]+n)-26);
    }
}
