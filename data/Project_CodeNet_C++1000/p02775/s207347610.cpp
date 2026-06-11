#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

int main(int, char**) {
        string n;
        cin >> n;
        ll len = n.size();
        int prev = 0;
        ll ans = 0;
        for (int i=len-1; i>=0; i--) {
                int num = n.at(i) - '0';
                num += prev; 
                if (num>5 || (num==5 && i!=0 && n.at(i-1)-'0'>4)) {
                        ans += (10 - num);
                        prev = 1;
                } else {
                        ans += num;
                        prev = 0;
                }
        }
        cout << ans+prev << endl;
        return 0;
}
