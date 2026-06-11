#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0, n;
    cin >> n;
    
    vector<int> score(40);
    int num = 1, point = 1;
    while (num < 40) {
        for (int i = 1; i <= point + 1; i++) {
            score[num] = point;
            num++;
        }
        point++;
    }
    
    for (long long i = 2; (i*i) <= n; i++) {
        int count = 0;
        while (n % i == 0 && n != 1) {
            n /= i;
            count++;
        }
        ans += score[count];
    }
    
    // -------------------------
    // 割っていった結果が素数なら1
    // -------------------------
    if (n != 1) {
        ans++;
    }
    // -------------------------
    
    cout << ans << endl;
    
    return 0;
}
