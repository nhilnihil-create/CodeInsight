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
    int h,w,m;
    cin >> h >> w >> m;
    vector<int> x(m), y(m);
    map<pair<int,int>,int> mp;

    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        mp[make_pair(x[i],y[i])] = 1;
    }

    map<int, int> row,col;
    
    for(int i = 0; i < m; i++){
        if(row.find(x[i]) == row.end()){
            row[x[i]] = 0;
        }
        row[x[i]] += 1;
        if(col.find(y[i]) == col.end()){
            col[y[i]] = 0;
        }
        col[y[i]] += 1;
    }

    int ans = 0;
    vector<int> m_x, m_y;
    int cnt = 0;
    for(auto it = row.begin(); it != row.end(); it++){
        if(cnt < it->second){
            cnt = it->second;
            m_x.clear();
            m_x.push_back(it->first);
        } else if(cnt == it->second){
            m_x.push_back(it->first);
        }
    }
    ans += cnt;
    cnt = 0;
    for(auto it = col.begin(); it != col.end(); it++){
        if(cnt < it->second){
            cnt = it->second;
            m_y.clear();
            m_y.push_back(it->first);
        } else if(cnt == it->second){
            m_y.push_back(it->first);
        }
    }
    ans += cnt;

    bool minus = true;
    for(int i = 0; i < m_x.size(); i++){
        for(int j = 0; j < m_y.size(); j++){
            if(mp.find(make_pair(m_x[i], m_y[j])) == mp.end()){
                minus = false;
                break;
            }
        }
    }
    if(minus) ans--;

    cout << ans << endl;

    return 0;
}