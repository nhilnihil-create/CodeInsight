#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
 
int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}
int *_p;
 
int main()
{
    int n;
    cin >> n;
    int *a = mallocint(n);
    int *l = mallocint(n);
    int *r = mallocint(n);
 
    for( int i = 0; i < n; i++ ) 
    {
        cin >> a[i];
        l[i] = a[i] + i;
        r[i] = -a[i] + i;
    }
 
    _p = l;
    sort(l, l + n);
    sort(r, r + n);

    
    int i = 0;
    int j = 0;
    _LL ans = 0;
    do
    {
        if( l[i] == r[j] )
        {
            _LL lcount = 1;
            while(i + lcount < n && l[i] == l[i + lcount] ) lcount++;
            _LL rcount = 1;
            while(j + rcount < n && r[j] == r[j + rcount] ) rcount++;
            ans += lcount * rcount;
            
            i += lcount;
            j += rcount; 
        }
        else
        {
            if( l[i] < r[j] )
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        /* code */
    } while (i < n && j < n);
    cout << ans;
}