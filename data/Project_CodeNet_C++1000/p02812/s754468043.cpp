#include<bits/stdc++.h>
using namespace std;
main()
{

    string str;
    int c=0,x;
    cin>>x;
    cin>>str;
    for(int i=0;i<x-2;i++)
    {
        if(str[i]=='A' && str[i+1]=='B' && str[i+2]=='C')
            c++;
    }
    cout << c << endl;

}
