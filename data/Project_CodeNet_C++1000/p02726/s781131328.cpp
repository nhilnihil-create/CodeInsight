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

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,x,y,i,j,r[2000];
    cin >> n >> x >> y;
    for (i,1,n)
        r[i]=0;
    for (i,1,n)
        for (j,i+1,n+1)
    {
        int ans = j-i;
        int bns = abs(j-y)+abs(i-x)+1;
        r[min(ans,bns)]++;
    }
    for (i,1,n)
        cout << r[i] << endl;
    return 0;
}
