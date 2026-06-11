#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pc __builtin_popcountll

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    int count = 0;
    ll x, y;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        ll sq_dist = (ll)(x * x) + (ll)(y * y);
        double dist = sqrt(sq_dist);
        if(dist <= d){
            ++count;
        }
    }
    cout << count << "\n";
    return 0;
}