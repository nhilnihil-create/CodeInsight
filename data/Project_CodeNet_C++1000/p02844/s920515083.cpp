#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    unordered_set<int> U1, U2, U3;
    for (int i = 0; i < N; ++i) {
        int s = S.at(i) - '0';
        for (int t : U2)
            U3.insert(10 * t + s);
        for (int t : U1)
            U2.insert(10 * t + s);
        U1.insert(s);
    }
    cout << U3.size() << endl;
}
