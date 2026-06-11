#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int N, X;
    cin >> N >> X;
    v<int> L(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    ll d = 0;
    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        d += L[i];
        if(d>X)break;
        cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}