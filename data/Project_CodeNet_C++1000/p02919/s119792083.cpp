#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    vector<int> ind(N);
    for(int i = 0; i < N; i++) ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int x, int y){
        return P[x] > P[y];
    });
    multiset<int> s;
    long long ans = 0;
    s.insert(-1), s.insert(-1), s.insert(N), s.insert(N);
    s.insert(ind[0]);
    long long a, b, c, d;
    for(int i = 1; i < N; i++){
        s.insert(ind[i]);
        auto ite = s.find(ind[i]);
        a = *next(ite, 1);
        b = *next(ite, 2);
        c = *prev(ite, 1);
        d = *prev(ite, 2);
        long long temp = (a - ind[i]) * (c - d) + (ind[i] - c) * (b - a);
        ans += P[ind[i]] * temp;
    }
    cout << ans << endl;
}