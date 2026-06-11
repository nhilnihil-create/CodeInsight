#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2;
    int br=0;
    cin >> s1 >> s2;
    for (int i=0;i<s1.size();i++)
        if(s1[i]!=s2[i])
            br++;
    cout << br;
}
