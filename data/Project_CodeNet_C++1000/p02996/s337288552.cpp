#include <bits/stdc++.h>
using namespace std;

bitset<(size_t)1e9> b;
int main(void) {
    int64_t N;
    int64_t sum;
    cin >> N;
    
    vector<pair<int64_t,int64_t>> ab(N);
    for(int i=0;i<N;i++) {
        cin >> ab[i].second >> ab[i].first;
    }

    sort(ab.begin(), ab.end());
    
    sum = 0;
    for(int i=0;i<N;i++) {
        sum += ab[i].second;
        if(sum> ab[i].first) {
            cout << "No\n";
            return 0;
        }
    }    

    cout << "Yes\n";
    return 0;
}
