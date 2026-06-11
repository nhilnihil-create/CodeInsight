#include <iostream>
using namespace std;
string result(string s)
{
    int len=s.length();
    if(len%2==0)
    return "No";
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        if(s[i]!=s[j])
        return "No";
    }
    int sec=(len-1)/2;
    for(int i=0,j=sec-1;i<j;i++,j--)
    {
        if(s[i]!=s[j])
        return "No";
    }
    int third=(len+3)/2;
    for(int i=third-1,j=len-1;i<j;i++,j--)
    {
        if(s[i]!=s[j])
        return "No";
    }
    return "Yes";
}


int main() {
    string inp;
    cin>>inp;
    cout<<result(inp);
}
