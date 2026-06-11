#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i < n; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> coor(n);
    for(int i = 0; i < n; i++){
        int x, l; cin >> x >> l;
        coor.at(i).first = x - l;
        coor.at(i).second = x + l;
    }

    sort(coor.begin(), coor.end(), [](pair<int, int> l, pair<int, int> r){
        return l.second < r.second;
    });

    int count = 1;
    int s = coor.at(0).first,t = coor.at(0).second;
    rep(i, n){
        if(t > coor.at(i).first) {
            continue;
        }
        s = coor.at(i).first;
        t = coor.at(i).second;
        count++;
    }
    cout << count << endl;
    return 0;
}

