#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int main(){
    int N;
    cin >> N;
    vector<P> C;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        C.push_back(make_pair(B, A));
    }

    sort(C.begin(), C.end());
    int time = 0;
    for (int i = 0; i < N; i++) {
        time += C.at(i).second;
        if (time > C.at(i).first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
