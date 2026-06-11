#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> x(n), l(n);
    vector<pair<pair<int,int>,int>> robot(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> l[i];
        robot[i] = {{x[i]+l[i], l[i]}, i};
    }
    sort(robot.begin(),robot.end());

    int ans = 0;
    set<int> pos;
    for(int i=0; i<n; i++){
        int r = robot[i].second;
        if(pos.upper_bound(x[r]-l[r]) == pos.lower_bound(x[r]+l[r])){
            ans += 1;
            pos.insert(x[r] - l[r]);
            pos.insert(x[r] + l[r]);
        }
        //for(auto p : pos) cout << p << " ";
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}