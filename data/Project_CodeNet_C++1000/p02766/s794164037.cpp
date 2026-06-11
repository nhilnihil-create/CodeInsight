#include <iostream>

using namespace std;

int solve(int n, int k)
{
    int cnt = 1;
    while(n >= k) {
        n = int((n - n%k) / k);
        cnt++;
    }

    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;

    return 0;
}