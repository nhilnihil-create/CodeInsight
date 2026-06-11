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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int cnt[26]={0};
        for(auto x: s)cnt[x-'a']++;
        string t="";
        for(int j=0;j<26;j++)t.push_back((cnt[j]+'0'));
        v.push_back(t);
    }
    ll sum=0;
    map<string,ll>mp;
    for(auto x: v)mp[x]++;
    for(map<string,ll>::iterator it=mp.begin();it!=mp.end();it++){
        ll y=it->second;
        sum+=(y*(y-1))/2;
    }
    cout<<sum<<endl;
}
