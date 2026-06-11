#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<char> vec(N);
    vector<char> vec_rev(N);
    for (int i=0; i<N; i++) {
        vec[i] = S[i];
        vec_rev[N-1-i] = S[i];
    }

    int count = 0;
    if (N%2 == 0) {
        for (int i=0; i<N/2; i++) {
            if (vec[i]!=vec_rev[i]) {
                count++;
            }
        }
    }
    else {
        for (int i=0; i<N/2; i++) {
            if (vec[i]!=vec_rev[i]) {
                count++;
            }
        }
    }
    cout << count << endl;
}