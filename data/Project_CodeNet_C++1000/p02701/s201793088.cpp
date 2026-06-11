#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0;i<N;i++) {
        cin >> S.at(i);
    }
    sort(S.begin(),S.end());
    S.erase(unique(S.begin(),S.end()),S.end());
    cout << (int)S.size() << endl;
}