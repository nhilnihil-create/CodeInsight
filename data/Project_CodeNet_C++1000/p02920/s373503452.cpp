#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    multiset<int> S1, S2, tmp;
    for(int i=0; i<(1<<N); i++) {
        int S;
        cin >> S;
        S1.insert(S);
    }

    cerr << *S1.rbegin() << endl;
    S2.insert(*S1.rbegin());
    S1.erase(--S1.end());

    for(int d=0; d<N; d++) {
        tmp = S2;
        for(auto itr=tmp.rbegin(); itr!=tmp.rend(); itr++) {
            auto l = S1.lower_bound(*itr);
            if(l == S1.begin()) {
                cout << "No" << endl;
                return 0;
            } else {
                --l;
                S2.insert(*l);
                S1.erase(l);
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
