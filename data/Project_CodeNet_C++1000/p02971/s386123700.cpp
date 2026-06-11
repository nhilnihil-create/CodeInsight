#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b)
{
    if(a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int m1 = 0;
    int m2 = 0;
    vector<int> A(N);
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
        if(chmax(m2, A[i]) && m2 > m1) swap(m1, m2);
    }
    for(int i=0; i<N; i++)
    {
        if(A[i]!=m1) cout << m1 << endl;
        else cout << m2 << endl;
    }

    return 0;
}
