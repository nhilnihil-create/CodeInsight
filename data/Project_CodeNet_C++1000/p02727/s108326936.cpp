#include<bits/stdc++.h>

using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, lli> pii;


int main()
{
    lli x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<pii> v;
    while(a--){
        lli x;
        cin >> x;
        v.push_back({x, 1});
    }
    while(b--){
        lli x;
        cin >> x;
        v.push_back({x, 2});
    }
    while(c--){
        lli x;
        cin >> x;
        v.push_back({x, 0});
    }
    sort(v.begin(), v.end(), greater<pii>());
    lli r=0, g=0, cl=0, ans=0;
    for(auto el: v){
        if(el.second == 0){
            if(r+g+cl < x+y){
                ans += el.first;
                cl++;
            }
        }
        if(el.second == 1){
            int rb = r+(g+cl-y);
            if(rb < x && r<x){
                ans += el.first;
                r++;
            }
        }
        if(el.second == 2){
            int gb = g+(r+cl-x);
            if(gb < y && g<y){
                ans += el.first;
                g++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
