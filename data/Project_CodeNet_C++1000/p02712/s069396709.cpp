#include <bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        long long int sum = 0;
        for (int x = 1; x <= n; ++x){
            if (x % 3 == 0 || x % 5 == 0) continue;
            sum += x;

        }
        cout << sum << endl;
    return 0;
}

