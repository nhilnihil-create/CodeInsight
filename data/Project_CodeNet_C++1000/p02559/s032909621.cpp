#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define int long long

struct BIT{
    vector<int> array;
    int n;

    BIT(int _n): array(_n+1, 0), n(_n){
    }

    // [1, i] の和、1-ind
    int sum(int i){
        int ans = 0;
        while(i != 0){
            ans += array[i];
            i -= i & (-i);
        }
        return ans;
    }

    // [i, j] の和、1-ind
    int sum(int i, int j){
        return sum(j) - sum(i-1);
    }

    // i に x を足す
    void add(int i, int x){
        while(i <= n){
            array[i] += x;
            i += i & (-i);
        }
    }
};

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, q;
    cin >> n >> q;
    BIT fw(n);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        fw.add(i+1, a);
    }
    for(int qq=0; qq<q; qq++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t) cout << fw.sum(a+1, b) << endl;
        else fw.add(a+1, b);
    }

    return 0;
}