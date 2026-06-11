#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define ii pair <int,int>
#define ever (;;)

const int N = 100100;

int n,a[N],p[N];
set <int> s;
set <int> :: iterator it;
ll ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        p[a[i]] = i;
    }

    for(int i=n;i>=1;i--)
    {
        int pos = p[i];
        if( i == n )
        {
            s.insert(pos);
            continue;
        }

        int a1 = -1 , a2 = -1 , b1 = -1 , b2 = -1;

        it = s.upper_bound(pos);
        if( it != s.end() )
            a1 = *it;
        if( a1 != -1 )
        {
            it = s.upper_bound(a1);
            if( it != s.end() )
                a2 = *it;
        }

        it = s.lower_bound(pos);
        if( it != s.begin() )
        {
            it--;
            b1 = *it;
        }
        if( b1 != -1 )
        {
            it = s.lower_bound(b1);
            if( it != s.begin() )
            {
                it--;
                b2 = *it;
            }
        }

        if( b1 != -1 )
        {
            int len1 = b1 - b2;
            if( b2 == -1 )
                len1 = b1;
            int len2 = a1 - pos;
            if( a1 == -1 )
                len2 = n-pos+1;

            ans += 1LL * len1 * len2 * i;
        }
        if( a1 != -1 )
        {
            int len1 = a2 - a1;
            if( a2 == -1 )
                len1 = n-a1+1;
            int len2 = pos-b1;
            if( b1 == -1 )
                len2 = pos;

            ans += 1LL * len1 * len2 * i;
        }

        s.insert(pos);
    }

    printf("%lld\n",ans);
}
