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
//#define sort(S) sort(all(S))

const int inf = 1e9;
const ll INF = 1e18;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int x,y,a,b,c,i;
    ll S=0;
    cin >> x >> y >> a >> b >> c;
    vector <int> A(a),B(b),C(c);
    for (i,0,a)
        cin >> A[i];
    for (i,0,b)
        cin >> B[i];
    for (i,0,c)
        cin >> C[i];
    sort(all(A),greater<int>()),sort(all(B),greater<int>());
    for (i,0,x)
    C.pb(A[i]);
    for (i,0,y)
    C.pb(B[i]);
    sort(all(C),greater<int>());
    for (i,0,x+y)
        S+=C[i];
    cout << S << endl;
    return 0;
}
