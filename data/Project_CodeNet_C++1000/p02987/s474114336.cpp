#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int sum=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(s[i]==s[j])
            {
                sum++;
            }
        }
    }
    if(sum==8)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}