#include <bits/stdc++.h>
//1:24 1:40
using namespace std;

int main() {
    //ifstream cin("data.in");
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i)
        cin>>b[i];
    for(int i=0; i<n; ++i) {
        if(b[i]<a[i]) {
            cout << -1;
            return 0;
        }
    }

    auto get_dif = [&] (int i) {
        return b[i] - b[(i - 1 + n) % n] - b[(i + 1) % n] ;
    };


    vector<int>dif(n);
    auto cmp = [&] (const int &i, const int &j) {
        if(b[i] == b[j])
            return i < j;
        return b[i] > b[j];
    };

    multiset<int, decltype(cmp)>S(cmp);
    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i] && get_dif(i) - a[i] >= 0)
            S.insert(i);
    }

    long long ops = 0;
    while(!S.empty()) {
        int poz = *S.begin();
        S.erase(S.begin());
        vector<int>neighb = {(poz - 1 + n) % n, (poz + 1 + n) % n};
        bool both_fixed = true;
        int sumNeighb = 0;
        for(int x : neighb) {
            if(S.find(x) != end(S))
                both_fixed = false;
            sumNeighb += b[x];
        }
        if(both_fixed) {
            int k = (b[poz] - a[poz]) / sumNeighb;
            if(!k) {
                cout << -1;
                return 0;
            }
            ops += k;
            b[poz] -= sumNeighb * k;
        } else {
            b[poz] -= sumNeighb;
            ops++;
        }

        for(int x : neighb)
        {
            if(S.find(x) == end(S) && get_dif(x) - a[x] >= 0)
                S.insert(x);
        }

        if(get_dif(poz) - a[poz] >= 0)
            S.insert(poz);
    }

    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << ops;
}
