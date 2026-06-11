#include <bits/stdc++.h>

using namespace std;
#define N 200200


int v[N];
int n, x, y, cnt, i, ok, ok1, l, r;
int main(){
    cin >> n;
    for (i = 0; i < n; ++i){
        cin >> v[i];
    }
    ok1 = 0;
    for (l = 0; l < n; ++l){
        for (r = l; r < n; ++r){
            swap(v[l], v[r]);
            ok = 1;
            for (i = 1; i < n; ++i)
                if (v[i] < v[i - 1])
                    ok = 0;
            if (ok)
                ok1 = 1;
            swap(v[l], v[r]);

        }
    }
    if (ok1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
