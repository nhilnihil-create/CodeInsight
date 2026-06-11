#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>

using namespace std;


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
int main() {
   /* map<int,pair<int,int>> mp;
    int n,m,problem;
    string s;
    cin >>n>>m;
    for(int i=0;i<m;i++){
        cin>>problem;
        cin >> s;
        if(s=="AC")mp[problem].first=1;
        else{
            if(mp[problem].first==0) mp[problem].second++;
        }
    }
    int ACs=0,WAs=0;
    for(auto i=mp.begin();i!=mp.end();i++){
        ACs+=i->second.first;
        WAs+=i->second.second;
    }
    cout << ACs <<" "<<WAs;*/


    int M, N; cin >> M >> N;
    int cnt[M]; bool found[M];
    int ans = 0;
    F0R(i, M) {
        cnt[i] = 0; found[i] = false;
    }
    int ans2 = 0;
    F0R(i, N) {
        int val; string S; cin >> val >> S; val--;
        if (S == "AC" && !found[val]) {
            found[val] = true; ans += cnt[val]; ans2++;
        } else {
            cnt[val]++;
        }
    }

    cout << ans2 << " " << ans << endl;

    return 0;



    return 0;

}
