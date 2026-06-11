//#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int* inputint(int n)
{
    int *ans = mallocint(n);
    for( int i = 0; i < n; i++ ) cin >> ans[i];
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *s = new int[n];
    int index = 0;
    while( index < n )
    {
        char c;
        cin >> c;
        char tmp = -1;
        if( c == 'R') tmp = 0;
        if( c == 'G') tmp = 1;
        if( c == 'B') tmp = 2;
        if( tmp >= 0 )
        {
            s[index++] = tmp;
        }
    }

    long long ans = 0;
    for( int i = 1; i < n - 1; i++ )
    {
        int target[2];
        int tmap[3];
        int c = s[i];
        tmap[c] = -1;
        index = 0;
        for( int j = 0; j < 3; j++)
        {
            if( j != c ) target[index++] = j;
        }
        for( index = 0; index < 2; index++)
        {
            tmap[target[index]] = index;
        }

        int l[2];
        int r[2];
        for (int j = 0; j < 2; j++)
        {
            l[j] = 0;
            r[j] = 0;
        }

        int samecount = 0;

        for( int d = 1; i - d >= 0 || i + d < n; d++ )
        {
            int flag = 0;
            if( i - d >= 0 && tmap[s[i-d]] >= 0 ) 
            {
                l[tmap[s[i-d]]]++;
                flag++;
            }
            if( i + d < n && tmap[s[i+d]] >= 0 )
            {
                r[tmap[s[i+d]]]++;
                flag++;
            } 
            if( flag == 2 && s[i-d] != s[i+d]) samecount++;
        }

        ans += l[0] * r[1] + l[1] * r[0] - samecount;
    }
    cout << ans;
}