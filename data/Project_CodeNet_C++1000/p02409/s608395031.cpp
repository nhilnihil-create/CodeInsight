#include <iostream>
#include <map>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int b, f, r, v;
    map<int, map<int, map<int, int> > > m;
    while (cin >> b >> f >> r >> v) {
        map<int, map<int, map<int, int> > >::iterator it = m.find(b);
        if (it == m.end()) {
            map<int, int> o; o.insert(make_pair(r, v));
            map<int, map<int, int> > n; n.insert(make_pair(f, o));
            m.insert(make_pair(b, n));
        }
        else {
            map<int, map<int, int> >::iterator it = m.at(b).find(f);
            if (it == m.at(b).end()) {
                map<int, int> o; o.insert(make_pair(r, v));
                m.at(b).insert(make_pair(f, o));
            }
            else {
                map<int, int>::iterator it = m.at(b).at(f).find(r);
                if (it == m.at(b).at(f).end()) {
                    m.at(b).at(f).insert(make_pair(r, v));
                }
                else {
                    it->second += v;
                }
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 10; k++) {
                try {
                    cout << " " << m.at(i).at(j).at(k);
                }
                catch(out_of_range&) {
                    cout << " " << 0;
                }
            }
            cout << "\n";
        }
        if (i < 4)
            cout << "####################" << "\n";
    }
}