#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len = s.length();
    int i,j=0;
    for(i=0;i<len;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            cout << s[i];
            j++;

        }
        if(j==3)break;
    }
}
