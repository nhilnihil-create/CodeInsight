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
    ll n;
    cin>>n;
    vector<ll>v;
    for(int i=1;i<10;i++)v.push_back(i);
    int cnt=0;
    while(cnt<n){
        ll x=v[cnt];
        cnt++;
        ll rem=x%10;
        if(rem==0){
            v.push_back(x*10);
            v.push_back((x*10)+1);
        }
        else if(rem==9){
            v.push_back((x*10)+9);
            v.push_back((x*10)+8);
        }
        else{
            v.push_back((x*10)+rem);
            v.push_back((x*10)+rem-1);
            v.push_back((x*10)+rem+1);
        }
    }
    sort(v.begin(),v.end());
    cout<<v[n-1]<<endl;
}
