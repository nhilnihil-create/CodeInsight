#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    cout << "print_vector -> ";
    for(int i=0; i<vec.size(); i++) {
        if(i == vec.size()-1) {
            cout << vec[i] << endl;
        }
        else {
            cout << vec[i] << " ";
        }
    }
    return;
}

vector<int> v;

void solve(int n) {
    if(n<=1) return;
    int l = sqrt(n);
    for(int i=2; i<=l; i++) {
        if(n%i==0) {
            solve(i); solve((int)(n/i)); return;
        }
    }
    v.push_back(n); return;
}

int main() {

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    vector<int> map(1000010, 0);

    for(int i=0; i<N; i++) {
        if(map[A[i]] >= 1) {
            map[A[i]]++;
            continue;
        }
        for(int j=A[i]; j<1000010; j+=A[i]) {
            map[j]++;
        }
    }

    int ans = 0;
    for(int a : A) {
        if(map[a] == 1) ans++;
    }
    cout << ans << endl;

    return 0;
}