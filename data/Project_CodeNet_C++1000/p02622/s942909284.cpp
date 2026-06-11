#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string s,t;
    int flg = 0;

    cin>>s>>t;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != t[i])
        {
            flg++;
        }
    }
    cout<<flg;

    cout<<endl;
    return 0;
}