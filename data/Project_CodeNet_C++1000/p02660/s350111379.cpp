#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    int res = 0;
    int last = -1;
    for(long long i = 2; i * i <= n; i ++){
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt ++;
        }
        for(int j = 1;; j ++){
            if(cnt < j) break;
            res ++;
            cnt -= j;
        }
    }
    if(n > 1) res ++;
    cout << res << "\n";
}
