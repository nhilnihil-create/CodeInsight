#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        p[i] = make_pair(a,i+1);
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());

    multiset<int> pos;
    pos.insert(0);
    pos.insert(0);
    pos.insert(n+1);
    pos.insert(n+1);

    long long int ans = 0;
    for(int i=0; i<n; i++){
        //cout << *prev(pos.lower_bound(q[i].second)) << " " << *pos.upper_bound(q[i].second) << endl;
        long long int left1  = p[i].second - *prev(pos.lower_bound(p[i].second));
        long long int left2  = *prev(pos.lower_bound(p[i].second)) - *prev(prev(pos.lower_bound(p[i].second)));
        long long int right1 = *pos.upper_bound(p[i].second) - p[i].second;
        long long int right2 = *next(pos.upper_bound(p[i].second)) - *pos.upper_bound(p[i].second);

        pos.insert(p[i].second);
        ans += p[i].first * (left1 * right2 + left2 * right1);
        //cout << p[i].first << " * (" << left1 << " * " << right2 << " + " << left2 << " * " << right1 << ")" << endl; 
    }
    cout << ans << endl;
    return 0;
}