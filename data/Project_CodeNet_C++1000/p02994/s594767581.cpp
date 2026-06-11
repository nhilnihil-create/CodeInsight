#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007

int main()
{
    int N, L;
    cin >> N >> L;
    ll sum = 0;
    int big = -13245;
    vector<int> A(N);
    int ans = 2345678;
    for (int i = 0; i < N; i++)
    {
        A[i] = i + L;
        sum += A[i];
        ans = min(ans, abs(A[i]));
        big = max(big,abs(A[i]));
    }
    if(A[N-1] < 0){
        cout << sum + ans << endl;
    }
    else{
        cout << sum - ans << endl;
    }
}
