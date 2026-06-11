#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;

int main(){
    long long n, d, a;
    cin >> n >> d >> a;
    vector<pair<long long, long long> > q(n);
    for(int i = 0; i < n; ++i) cin >> q[i].first >> q[i].second;
    sort(q.begin(), q.end());

    long long ans = 0, dmg = 0;
    queue<pair<long long, long long> > m;
    for(int i = 0; i < n; ++i){
        while(!m.empty()){
            if(q[i].first > m.front().first){
                dmg -= m.front().second;
                m.pop();
            }
            else break;
        }
        long long hp = q[i].second - dmg;
        if(hp > 0){
            long long pl = hp / a + !(!(hp % a));
            ans += pl;
            dmg += pl * a;
            m.push(make_pair(q[i].first + 2 * d, pl * a));
        }
    }
    cout << ans;
}