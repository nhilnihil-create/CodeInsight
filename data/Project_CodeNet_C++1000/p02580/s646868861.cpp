#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e5+5, M = 1e6+6, OO = 0x3f3f3f3f;
int h,w, m;
set<pair<int, int> > st;
map<int, ll> ros, cols;
// vector<pair<int, int> > targets;
int main()
{
    FIO
    cin>>h>>w>>m;

    for(int i  = 0 ; i<m ; i++)
    {
        int tr, tc; cin>>tr>>tc;
        tr--, tc--;
        ros[tr]++; cols[tc]++;
        st.insert({tr, tc});
    }
    vector<pair<ll, int> > rs, cs;
    for(auto p : ros)
        rs.push_back({p.second, p.first});
    for(auto c : cols)
        cs.push_back({c.second, c.first});
    sort(rs.begin(), rs.end(), greater<pair<ll, int> > ());
    sort(cs.begin(), cs.end(), greater<pair<ll, int> > ());
    ll numofmxros = 0, numofmxcols = 0;
    multiset<int> str, stc;
    for(auto x : rs)
    {
        if(x.first != rs[0].first)
            break;
        numofmxros++;
        str.insert(x.second);
    }
    for(auto x : cs)
    {
        if(x.first != cs[0].first)
            break;
        numofmxcols++;
        stc.insert(x.second);
    }
    ll mx = rs[0].first + cs[0].first;
    // for(int i = 0 ; i< (int) rs.size() ; i++)
    // {
    //     ll tmpmx = -1;
    //     // cout<<"row: "<<i<<" "<<rs[i].first<<" "<<rs[i].second<<endl;
    //     for(int j = 0 ; j < (int) cs.size(); j++)
    //     {
    //         // cout<<"col:" <<j<<" "<<cs[j].first<<" "<<cs[j].second<<endl;
    //         tmpmx = max(tmpmx, rs[i].first + cs[j].first - (int)(st.count({rs[i].second, cs[j].second}))); 
    //     }
    //     if(tmpmx <= mx)
    //         break;
    //     mx = tmpmx;
    // }
    // cout<<mx<<endl;
    ll numofOptions = numofmxcols * numofmxros;
    for(auto target : st)
    {
        if(stc.count(target.second) && str.count(target.first))
            numofOptions--;
    }
    numofOptions ? cout<<mx : cout<<mx-1;
    return 0;
}