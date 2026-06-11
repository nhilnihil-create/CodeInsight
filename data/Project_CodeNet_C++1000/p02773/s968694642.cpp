#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    map <string, int> mp ;
    string str ;
    int n ;
    cin >> n ;
    while(n--)
    {
        cin >> str ;
        mp[str]++ ;
    }
    int mx = 0 ;
    for(auto i:mp)
    {
        if(i.second > mx) mx = i.second;
    }
    for(auto i:mp)
    {
        if(i.second == mx) cout << i.first << endl ;
    }

}
