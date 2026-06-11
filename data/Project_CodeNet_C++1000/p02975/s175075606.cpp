#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double

bool check(vector<int> & seq, vector<int> & start) {
    for (int i=0; i<seq.size(); i++) {
        if ((seq[i] ^ seq[(i + 1) % seq.size()] ^ seq[(i + 2) % seq.size()]) != 0) return 0;
    }
    sort(all(seq));
    sort(all(start));
    return start == seq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int,int> cnt;
    vector<int> start(n);
    for (int i=0; i<n; i++) {
        cin >> start[i];
        cnt[start[i]]++;
    }
    if(cnt.size()>4){
        cout<<"No\n";
        return 0;
    }
    for (auto x:cnt) {
        for (auto y:cnt) {
            for (auto z:cnt) {
                vector<int> seq;
                for (int i=0; i<n; i++) {
                    if (i%3 == 0) seq.pb(x.x);
                    if (i%3 == 1) seq.pb(y.x);
                    if (i%3 == 2) seq.pb(z.x);
                }
                if (check(seq, start)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
