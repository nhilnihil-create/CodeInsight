#include<bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;

int main()
{
    int N; cin >> N;
    vector<pair<int,int>>v;
    for(int i = 0; i < N; i++)
    {
        int x,l; cin >> x >> l;
        v.push_back(pair(x+l,x-l));
    }
    sort(v.begin(),v.end());
    int ans = 1;
    int r = v[0].first;
    for(int i = 0; i < N-1; i++)
    {
        if(v[i+1].second < r) continue;
        ans++;
        r = v[i+1].first;
    }
    cout << ans << endl;
}