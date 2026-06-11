#include <iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int cnt=0;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++)  cnt+=(s1[i]!=s2[i]);
    cout<<cnt<<endl;
    return 0;
}