#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main() {
    int h,w,m; cin >> h >> w >> m;

    vector<int> hcnt(h,0);
    vector<int> wcnt(w,0);
    int hm = 0;
    int wm = 0;
    set<pair<int,int>> bomb;
    int cnt = -1;
    for(int i=0; i<m; i++){
        int y; int x;
        cin >> y >> x;
        y--; x--;

        bomb.insert(make_pair(y,x));
        hcnt[y]++;
        wcnt[x]++;
        if(hcnt[y] > hm) hm = hcnt[y];
        if(wcnt[x] > wm) wm = wcnt[x];
    }

    vector<int> hn;
    vector<int> wn;
    for(int i=0; i<h; i++){
        if(hcnt[i] == hm) hn.push_back(i);
    }
    for(int i=0; i<w; i++){
        if(wcnt[i] == wm) wn.push_back(i);
    }

    for(int i=0; i<hn.size(); i++){
        for(int j=0; j<wn.size(); j++){
            if(bomb.count(pair<int,int>(hn[i],wn[j]))) continue;
            cout << hm + wm << endl;
            return 0;
        }
    }
    cout << hm + wm -1 << endl;
}