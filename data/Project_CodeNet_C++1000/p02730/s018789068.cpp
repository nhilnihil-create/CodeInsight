#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<iterator>
#include<iomanip>
#include<string>
using namespace std;

int palindrome (string s)
{
    for (int i=0; i<s.size()/2; i++)
    {
        if (s[i]!=s[s.size()-1-i]) {return 0;}
    }
    for (int i=0; i<(s.size()-3)/2; i++)
    {
        if (s[i]!=s[(s.size()/2)-1-i]) {return 0;}
    }
    return 1;
}

int main()
{
    string str;
    cin>>str;
    if (palindrome (str)) {cout<<"Yes";}
    else {cout<<"No";}
    return 0;
}
