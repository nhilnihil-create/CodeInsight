#include <iostream>

using namespace std;

int main()
{
    int flag=0;
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A'&& (i+2)<n && s[i+1]=='B'&&s[i+2]=='C')
        {
            flag++;
        }

    }
    cout<<flag;
    return 0;
}
