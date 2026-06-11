#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> p(m);
    vector<bool> s(m);
    for(int i = 0; i < m; i++){
        string tmp;
        cin >> p[i] >> tmp;
        p[i]--;
        if(tmp == "AC") s[i] = true;
        else s[i] = false;
    }

    vector<pair<bool, int> > cnt(n,make_pair(false, 0));

    for(int i = 0; i < m; i++){
        if(cnt[p[i]].first == true) continue;
        if(s[i] == false) cnt[p[i]].second++;
        if(s[i] == true) cnt[p[i]].first = true;
    }

    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i].first == true){
            ans1++;
            ans2 += cnt[i].second;
        }
    }

    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}