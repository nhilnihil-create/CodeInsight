#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> z(n);

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        z[i] = make_pair(x,y);
    }

    map<pair<int,int>,int> c;

    sort(z.begin(),z.end());

    int ans = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int p = z[j].first-z[i].first;
            int q = z[j].second-z[i].second;
            c[make_pair(p,q)]++;
            ans = max(ans,c[make_pair(p,q)]);
        }
    }

    ans = n-ans;

    cout << ans << endl;




    
    return 0;
}