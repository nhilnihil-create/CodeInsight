#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG

int main(){
    int N;
    vector<int> As(200010);

    cin >> N;
    As.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> As[i];
    }

    vector<int> Cs(N);
    copy(As.begin(), As.end(), Cs.begin());
    sort(Cs.begin(), Cs.end());

    for (int A: As) {
        if (A == Cs[N-1]) {
            cout << Cs[N-2] << '\n';
        } else {
            cout << Cs[N-1] << '\n';
        }
    }
    
    return 0;
}