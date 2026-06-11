#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}


signed main(){

    int k, q;
    cin >> k >> q;
    vector<int> d(k);
    for(int i = 0; i < k; ++i)
        cin >> d[i];
    vector<int> vn(q), vx(q), vm(q);
    for(int i = 0; i < q; ++i)
        cin >> vn[i] >> vx[i] >> vm[i];

    for(int i = 0; i < q; ++i){
        int n = vn[i];
        int m = vm[i];
        int x = vx[i] % m;
        vector<int> a(k);
        for(int j = 0; j < k; ++j)
            a[j] = d[j] % m;
        i64 sum = accumulate(a.begin(), a.end(), 0LL);
        --n;

        // n - 0が出る個数 - 繰り上がりの回数

        i64 t_sum = sum * (n / k) + x;
        i64 zero_cnt = count(a.begin(), a.end(), 0) * (n / k);
        // cout << t_sum << " : " << n / k << endl;
        for(int j = 0; j < n % k; ++j){
            t_sum += a[j];
            zero_cnt += (a[j] == 0);
        }

        /*
        cout << endl;
        for(int j = 0; j < k; ++j)
            cout << a[j] << " \n"[j + 1 == k];
            */
        cout << n - t_sum / m - zero_cnt << endl;
        // cout << "\n------\n";
    }
}
