#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, cnt=0;
    cin >> x;
    string s;
    cin>>s;
    for(int i=0; i<s.length()-2;i++)
    {
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
            cnt++;
    }

    cout<<cnt<<"\n";

}
