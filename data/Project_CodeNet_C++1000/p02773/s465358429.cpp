#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    int n;

    cin >> n;

    map <string, int> mp;
    map <string, int> :: iterator it;


    while(n--)
    {
        string s;

        cin >> s;

        mp[s]++;

    }

    int mx = INT_MIN;

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        int z = (*it).second;

        mx = max(mx, z);
    }

    vector <string> v;

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if((*it).second == mx)
        {
            v.push_back((*it).first);
        }
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }




}








