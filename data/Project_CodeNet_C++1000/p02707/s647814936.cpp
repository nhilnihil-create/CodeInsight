#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N, 0);

    for (int i = 1; i < N; i++) {
        cin >> A.at(i);
        A.at(i)--;
        B.at(A.at(i))++;
    }

    for (int i = 0; i < N; i++) cout << B.at(i) << endl;
    
    return 0;
}