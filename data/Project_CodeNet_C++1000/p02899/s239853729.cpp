#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<pair<int, int> > A(N);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i).first;
    A.at(i).second = i + 1;
    }

    sort(A.begin(),A.end());

    for(int i = 0; i < N; i++) {
        cout << A.at(i).second;
        if (i < N - 1)
        {
            cout << ' ';
        }
        
    }
    cout << endl;




    return 0;
}