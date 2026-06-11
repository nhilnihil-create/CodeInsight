#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int k , x;

int main()
{
    _FastIO;
    cin >> k >> x;
    for(int i = x - k + 1; i < x + k; i++){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
