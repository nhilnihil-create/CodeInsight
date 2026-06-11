#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++)
    {
    cin >> A.at(i);
    }
    int ans = 1 << 30;
    int temp = 0;
    for (int i = 1; i <= 100; i++)
    {
        temp = 0;
        for (int j = 0; j < N; j++)
        {
            temp += pow(A.at(j) - i,2);
        }
        ans = min(ans,temp);
    }
    cout << ans << endl;
  

    return 0;
}