
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 


int main()
{

    int N;
    cin >> N;

    int cnt = 1;
    cnt <<= N;

    multiset< int, greater<int> > S; 

    for (int i = 0; i < cnt; ++i) {
        int life;
        cin >> life;
        S.insert(life);
    }

    bool ok = true;
    multiset< int, greater<int> > curr; //! current slimes
    curr.insert(*S.begin());
    S.erase(S.begin());

    for (int i = 0; ok && i < N; ++i) { //! repeat N generations
        // cout << "Generation " << i << endl;
        // dump(S);
        // dump(curr);
        auto ik = S.begin(); //! iterator to find new kids
        vector<int> newKids;
        for (int p : curr) { //! for each slime in the current generation
            // cout << "\tparent = " << p << endl;
            while (ik != S.end() && p <= *ik) ++ik;
            if (ik == S.end()) {
                // cout << "\t\tno valid kid" << endl;
                ok = false;    
                break;    
            } else {
                // cout << "\t\tkid = " << (*ik) << endl;
                newKids.push_back(*ik);
                ++ik;
            }
        }
        if (ok) {
            for (int k : newKids) {
                curr.insert(k);
                S.erase(S.find(k));
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
