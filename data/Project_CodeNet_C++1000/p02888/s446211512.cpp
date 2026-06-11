#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
    cin >> N;
    vector<int>L(N);
    for (int i = 0; i < N; i++) {
        cin >> L.at(i);
    }
    sort(L.begin(), L.end());
    int count = 0;

    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            int add = L.at(i) + L.at(j);
            int ok = j, ng = N;
            while (ng - ok > 1) {
                int mid = ok + (ng - ok) / 2;
                if (L.at(mid) < add) {
                    ok = mid;
                }
                else {
                    ng = mid; 
                }
            }
            count += ok - j;
        }
    }
    cout << count << endl;
}