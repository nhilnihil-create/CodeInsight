#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf=-1e9;
bool cmp(pair<int,int>a,pair<int,int>b) {
    return a.second<b.second;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++) {
        int x,l;
        cin>>x>>l;
        v.push_back({x-l,x+l});
    }
    sort(v.begin(),v.end(),cmp);
    // for(auto x:v) cout<<x.first<<" "<<x.second<<endl;
    int ans=0;
    int last=inf;
    for(auto x:v) {
        if(x.first>=last) {
            ans++;
            last=x.second;
        }
    }
    cout<<ans<<endl;
}