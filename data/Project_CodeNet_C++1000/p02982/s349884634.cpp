#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, D;
    cin >> N >> D;
    vector<vector<int>>vec(N, vector<int>(D, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<D; j++) {
            int p;
            cin >> p;
            vec[i][j] = p;
        }
    }

    int sum_ = 0;
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            double num = 0;
            for (int k=0; k<D; k++) {
                num += pow(vec[i][k] - vec[j][k], 2);
            }

            if (floor(sqrt(num)) == sqrt(num)) {
                sum_ += 1;
            }

        }
    }

    cout << sum_ << endl;
    return 0;
}