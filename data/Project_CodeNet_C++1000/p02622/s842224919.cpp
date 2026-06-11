#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arrNM[200];

int main()
{
    string s;
    string t;
    cin>>s>>t;
    int result=0;
    for(int i=0 ; i<s.size() ; i++)
    {
        if(s[i] != t[i])
            result++;
    }


    cout<<result;


    return 0;
}
