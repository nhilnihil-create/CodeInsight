#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long

#define for(i,a,b) for (i=a; i<b; i++)
#define forb(i,a,b) for (i=a; i>b; i--)
#define all(S) S.begin(),S.end()
#define sort(S) sort(all(S))

const int inf = 1e9+7;
const ll INF = 1e18;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,i;
    cin >> n;
    vector <int> A(n),B(n);
    for (i,0,n)
        cin >> A[i] >> B[i];
    sort(A);
    sort(B);
    if (n&1)
        cout << B[n/2]-A[n/2]+1 << endl;
    else
        cout << B[n/2]+B[n/2-1]-A[n/2]-A[n/2-1]+1 << endl;
    return 0;
}
