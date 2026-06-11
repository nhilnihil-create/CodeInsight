#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2,u;
    int g1,g2;
    cin >> s1 >> s2;
    cin >> g1 >> g2;
    cin >> u;
    if(s1==u)
        g1--;
    if(s2==u)
        g2--;
    cout << g1 << " " << g2;
}
