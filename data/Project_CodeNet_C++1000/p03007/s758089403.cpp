#include <bits/stdc++.h>
using namespace std; 
const int maxn = 100500;
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > pos, neg;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        if(x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }
    vector < pair < int, int > > ops;
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());
    if((int)pos.size() == 0){
        ops.push_back({neg[0], neg[1]});
        pos.push_back(neg[0] - neg[1]);
        neg.erase(neg.begin(), neg.begin() + 2);
    }
    if((int)neg.size() == 0 && (int)pos.size() != 1){
        ops.push_back({pos[0], pos[1]});
        neg.push_back(pos[0] - pos[1]);
        pos.erase(pos.begin(), pos.begin() + 2);
    }
    int i = 0, j = 0;
    if((int)neg.size() > 0){
        long long sm = neg[0];
        for(int i = 0 ; i < (int)pos.size() - 1 ; ++i){
            ops.push_back({sm, pos[i]});
            sm -= pos[i];
        }
        if((int)pos.size() > 0){
            ops.push_back({pos.back(), sm});
            sm = pos.back() - sm;
        }
        
        for(int i = 1 ; i < (int)neg.size() ; ++i){
            ops.push_back({sm, neg[i]});
            sm -= neg[i];
        }
    }
    cout << ops.back().first - ops.back().second << '\n';
    for(auto op : ops)
        cout << op.first << ' ' << op.second << '\n';
    return 0;

}