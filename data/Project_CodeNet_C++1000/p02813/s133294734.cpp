#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int kaijo(int n) {
    if(n <= 1) {
        return 1;
    }
    return kaijo(n-1)*n;
}


int nom(vector<int> A) {
    int ans = 0;
    int N = A.size();
    vector<int> a(N,1);

    for(int i = 0; i < N; i++) {
        a.at(A.at(i) - 1) = 0;
        for(int j = 0; j < A.at(i); j++) {
            ans += a.at(j)*kaijo(N - 1 - i);
        }
    }


    return ans;
}

int main() {
    int N = 0;
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P.at(i);
    }
    vector<int> Q(N);
    for(int i = 0; i < N; i++) {
        cin >> Q.at(i);
    }
    cout << abs(nom(P) - nom(Q)) << endl;



    return 0;
}