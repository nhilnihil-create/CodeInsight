#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    map <string, int> mp;
    map <string, int>::iterator it;
    int t,mx=0;
    cin >>t;

while(t--)
{
    string s;
    cin >> s;
    mp[s]++;
    if(mp[s] > mx)
    mx = mp[s];
}
for(it = mp.begin(); it!=mp.end(); it++)
{
    if(it ->second == mx)
        cout << it->first << endl;
}

return 0;
}