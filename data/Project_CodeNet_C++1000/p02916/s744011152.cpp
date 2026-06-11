#include <bits/stdc++.h>
using namespace std;

void solve(int N, vector<int> A, vector<int> B, vector<int> C)
{
    int res = 0;
    int prev = N;
    for (int i = 0; i < N; i++)
    {
        res += B.at(A.at(i) - 1);
        if (prev + 1 == A.at(i))
            res += C.at(prev - 1);
        prev = A.at(i);
    }
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    vector<int> C(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> C.at(i);
    }
    solve(N, move(A), move(B), move(C));
    return 0;
}
