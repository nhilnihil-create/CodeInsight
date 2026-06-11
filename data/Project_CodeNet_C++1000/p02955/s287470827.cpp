#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    int N, K;
    int A[505];
    int sum = 0;
    int ans = 1;
    vector < int > divisor;

    cin >> N >> K;
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
        sum += A[i];
    }
    
    for ( ll i = 1; i * i <= sum; i++ ) {
        if ( sum % i == 0 ) {
            divisor.push_back(i);
            if ( i != sum / i ) divisor.push_back(sum / i);
        }
    }

    for ( int div : divisor ) {
        vector < ll > da, db;
        da.push_back(0); db.push_back(0);
        for ( int i = 0; i < N; i++ ) {
            ll dda = (A[i] + div - 1) / div * div - A[i];
            ll ddb = A[i] - A[i] / div * div;
            if ( dda > 0 ) {
                da.push_back(dda);
                db.push_back(ddb);
            }
        }
        sort(begin(da), end(da));
        sort(begin(db), end(db));
        for ( int i = 1; i < da.size(); i++ ) {
            da[i] += da[i - 1];
            db[i] += db[i - 1];
        }
        for ( int i = 0; i < da.size(); i++ ) {
            if ( da[i] == db[(int)da.size() - i - 1] && da[i] <= K ) {
                ans = max(ans, div);
            }
        }
    }

    cout << ans << endl;

    return ( 0 );
}
