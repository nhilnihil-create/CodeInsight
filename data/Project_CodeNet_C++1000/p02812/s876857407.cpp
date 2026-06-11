#include<bits/stdc++.h>
using namespace std;
int abc(string s, int n)
{
    int cnt=0;
    for (int i=0; i<n-2; i++)
    {
        if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
            cnt ++;
    }
    return cnt;
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    cout << abc(s, n) << endl;
    return 0;
}