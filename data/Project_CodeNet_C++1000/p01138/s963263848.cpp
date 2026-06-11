#include <bits/stdc++.h>

using namespace std;
using i64 = long long int;
using ui64 = unsigned long long int;

////////////////////////////////

int main()
{
    const int day = 24 * 60 * 60;
    vector<int> imos;
    int n;
    while(cin >> n,n){
        imos.assign(day + 1, 0);
        for(int i=0;i<n;i++){
            string s,t;
            cin >> s >> t;
            int ts = stoi(s.substr(0,2)) * 60 * 60 + stoi(s.substr(3,2)) * 60 + stoi(s.substr(6,2));
            int tt = stoi(t.substr(0,2)) * 60 * 60 + stoi(t.substr(3,2)) * 60 + stoi(t.substr(6,2));
            // cerr << s << " " << t << " " << ts << " " << tt << endl;
            imos[ts]++;imos[tt]--;
        }
        for(int i=0;i<day;i++){
            imos[i+1] += imos[i];
        }
        int res = 1;
        for(int i=0;i<day+1;i++){
            res = max(res,imos[i]);
        }
        // cerr << imos[10800] << endl;
        cout << res << endl;
    }

}


