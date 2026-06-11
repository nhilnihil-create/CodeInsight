#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> p(N);
    for(int i=0;i<N;i++) {
        cin >> p.at(i);
    }
    sort(p.begin(),p.end());
    cout << accumulate(p.begin(),p.end()-p.size()+K,0) << endl;
}