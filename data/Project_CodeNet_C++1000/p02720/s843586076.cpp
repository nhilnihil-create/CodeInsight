#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
        int k;
        cin >> k;
        vector<ll> a(9);
        rep(i,9) a[i] = i+1;
        int i = 0;
        while(1){
                if (k <= a.size()){
                        cout << a[k-1] << endl;
                        return 0;
                }
                ll n = a[i];
                ll t = n % 10;
                if (t != 0) a.push_back(n*10 + t - 1);
                a.push_back(n*10 + t);
                if (t != 9) a.push_back(n*10 + t + 1);
                i++;
        }

}