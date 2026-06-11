#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();

    int n, m, sum= 0;
    cin>> n >> m;

    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>> a[i];
        sum+= a[i];
    }

    sort(a, a+n, greater<int>());

    cout <<(a[m-1] <  ( sum/(4.0*m)) ? "No\n" :"Yes\n");


            return 0;
}


