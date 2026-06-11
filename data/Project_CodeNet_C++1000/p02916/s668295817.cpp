#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io(); 
    int n; cin >> n;
    vector<pair<int,int>> vp;
    int dist[n];
    int fs = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        pair<int,int> p = {x,0};
        vp.push_back(p);
        dist[x - 1] = i;
    }
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        fs += x;
    }
    for(int i = 0; i < n - 1; ++i){
        int x; cin >> x;
        vp[dist[i]].second += x;
    }
    
    for(int i = 1; i < (int)vp.size(); ++i){
        if(vp[i].first == vp[i - 1].first + 1){
            fs += vp[i - 1].second;
        }
    }
    return cout << fs << '\n', 0;
}