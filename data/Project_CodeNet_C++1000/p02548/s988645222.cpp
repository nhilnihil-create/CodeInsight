#include <bits/stdc++.h>
using namespace std;

#define  rep(i,n)   for(int i=0; i<(int)n; i++)
#define  per(i,n)   for(int i=((int)n)-1; i>=0; i--)
#define  mem(x,y)   memset(x,y,sizeof(x))
#define  read(f)    freopen(f, "r", stdin)
#define  write(f)   freopen(f, "w", stdout)
#define  pii        pair<int,int>
#define  mp         make_pair
#define  ff         first
#define  ll         long long
#define  ss         second
#define  pb         push_back
#define  __         printf("\n")
#define  N          1000000

vector <int> divisor[N + 5];

void count_div()
{
    for( int i = 1; i <= N; i++ )
    {
        for( int j = i ; j <= N; j += i )
            divisor[j ].pb( i );
    }
    return;
}

int main()
{
    count_div();
    int n;
    while( cin >> n )
    {
        ll t = n, sum = 0;
        rep( i, n - 1 )
        {
            sum += divisor[t - ( i + 1 )].size();
        }
        cout << sum << endl;
    }
    return 0;
}
