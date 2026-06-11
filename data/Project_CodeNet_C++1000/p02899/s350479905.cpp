/*    Mohammed Sami Khan
                       মোহাম্মদ সামী খান
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define mp(a,b) make_pair(a,b)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;

bool sortbysecc(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

int main()
{
    fastio;
    ll t, n, m, x, y, p, q, r, i, j, d, f=0;
    char *ye="YES", *no="NO";
    cin>>n;
    vector<pair<int, int> > v;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];

        v.push_back(mp(a[i], i+1));
    }
    sort(v.begin(), v.end());
    for(i=0;i<n;i++){
        cout<<v[i].second<<" ";
    }

}
