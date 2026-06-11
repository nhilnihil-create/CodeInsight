#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define leading zero str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
string text="abcdefghijklmnopqrstuvwxyz";
const int maxn=1e6+7;
//        .--------------.
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'
bool cmp(const pair<string,int>& a,const pair<string,int>& b)
{
    if(a.second==b.second)return a.first<b.first;
    else return a.second>b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>v;
    map<string,int>mp;
    int k=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    vector<pair<string,int> >p;
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        p.push_back({it->first,it->second});
    }
    sort(p.begin(),p.end(),cmp);
    v.push_back(p[0].first);
    k=p[0].second;
    for(int i=1;i<p.size();i++){
        if(k==p[i].second)v.push_back(p[i].first);
    }
    for(auto &x: v)cout<<x<<endl;
}
