#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a;
    cin >> n;
    set<int>se;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a = n;
            while (a%i==0) {
                a /= i;
            }
            if (a % i == 1) {
                se.insert(i);
            }

            int b = n / i;
            a = n;
            while (a % b == 0) {
                a /= b;
            }
            if (a % b == 1) {
                se.insert(b);
            }
        }
    }
    se.insert(n);
    n--;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            se.insert(i);
            se.insert(n / i);
        }
    }
    se.insert(n);
    se.erase(1);
    cout << se.size() << endl;



}
