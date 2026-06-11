//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    int a;
    cin >> a;

    char x[a], y[a];
    for(int i = 0 ; i < a ; i++) cin >> x[i];
    for(int i = 0 ; i < a ; i++) cin >> y[i];
    for(int i = 0 ; i < a ; i++){
        cout << x[i] << y[i];
    }

    cout << endl;

    return 0;
}
