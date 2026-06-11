#include <iostream>
#include <vector>
#include <algorithm>
#include<utility>
using namespace std;


int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector< pair<int, int> > v;
    for(int i = 0; i < a; i++) {
        int tmp;
        cin >> tmp;
        pair<int, int> p = make_pair(tmp, 0);
        v.push_back(p);
    }
    for(int i = 0; i < b; i++) {
        int tmp;
        cin >> tmp;
        pair<int, int> p = make_pair(tmp, 1);
        v.push_back(p);
    }
    for(int i = 0; i < c; i++) {
        int tmp;
        cin >> tmp;
        pair<int, int> p = make_pair(tmp, 2);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long cnt0 = 0, cnt1 = 0, cnt2 = 0;
    long long ret = 0;
    for(int i = 0; i < v.size(); i++) {
        if(cnt0 + cnt1 + cnt2 == x+y) break;
        if(v[i].second == 0 && cnt0 < x) {
            ret += v[i].first;
            cnt0++;
        } else if(v[i].second == 1 && cnt1 < y) {
            ret += v[i].first;
            cnt1++;
        } else if(v[i].second == 2){
            ret += v[i].first;
            cnt2++;
        }
    }
    cout << ret << endl;
    return 0;
}