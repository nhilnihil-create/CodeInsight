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

const int inf = 1e9;
const ll INF = 1e18;

int gcd(int a, int b)
{
    if (a<b)
        swap(a,b);
    if (b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int k,i,j,q;
    ll s = 0;
    cin >> k;
    for (i,1,k+1)
        for (j,1,k+1)
        for (q,1,k+1)
        s+=gcd(gcd(i,j),q);
    cout << s << endl;
    return 0;
}
