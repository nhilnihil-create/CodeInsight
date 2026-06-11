#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define all(v) v.begin(),v.end()
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    fast ;
    int n,i,t;
    string s;
    map< string,int > m;
    vector< pair< int,string > >v;
    vector<string>x;
    cin >> t ;
    while(t--)
    {
        cin >> s ;
        m[s]++;
    }
    int mx=0;
    for(auto it =m.begin() ; it!= m.end() ; it++)
    {
        int a = it->second ;
        string y = it->first ;
        if(a>mx)mx=a;
        v.push_back(make_pair(a,y) ) ;
    }
    sort(v.rbegin(),v.rend());
    for(i = 0 ; i < v.size() ; i++)
    {
        if(v[i].first==mx)
            x.push_back(v[i].second);
    }
    sort(x.begin(),x.end());
    for(auto it :x)
        cout << it << "\n";
    cout << "\n";

    return 0;
}
