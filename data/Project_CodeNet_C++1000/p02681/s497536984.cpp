#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    int flag = 0;
    for( int i=0 ; i < s1.size(); i++ )
    {
        if(  s1[i] != s2[i] )flag=1;
    }
    if(flag == 1)cout<<"No\n";
    else cout<<"Yes\n";

    return 0;
}
