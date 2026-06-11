#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >>s;
    int l=0,r=s.length()-1,c=0;
    while(l<=r)
    {
        if(s[l]!=s[r])
        {
            c++;
        }
        l++,r--;
    }
    cout <<c;
}