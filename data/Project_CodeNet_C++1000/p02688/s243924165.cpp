#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K; cin >> N >> K;
    set<int> ans;
    for(int i=0; i<K; i++){
        int d; cin >> d;
        for(int j=0; j<d; j++){
            int A; cin >> A;
            ans.insert(A);
        }
    }
    cout << N-ans.size() << endl;
}
