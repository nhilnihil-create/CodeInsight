#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int M = N;
    int d = 1;
    while (M/ 10 > 0)
    {
        d++;
        M /= 10;
    }

    int ans = 0;
    for (int i = 1; i <= d; i++)
    {
        if (i % 2 == 1)
        {
            if (i != d)
            {
                ans += pow(10, i) - pow(10, i - 1);
            } else
            {
                ans += N - pow(10, i - 1) + 1;
            }    
        }
        
    }
    cout << ans << endl;

  return 0;
}
