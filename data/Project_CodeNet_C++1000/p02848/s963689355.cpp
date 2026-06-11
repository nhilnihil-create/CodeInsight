#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int len=s.length();

    for (int i=0;i<len;i++){
        int temp=s[i]-'A';
        temp=(temp+n)%26;
        s[i]='A'+temp;
    }
    cout<<s<<endl;
}