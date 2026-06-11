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
    int c, k, n;
    cin >> n >> k >> c;
    int *s = new int[n];
    int index = 0;
    while( index < n )
    {
        char c;
        cin >> c;
        char tmp = -1;
        if( c == 'o') tmp = 0;
        if( c == 'x') tmp = 1;
        if( tmp >= 0 ) s[index++] = tmp;
    }

    // i日目から全力で働いた場合の働ける日数
    int *fr = new int[n];
    for( int i = n - 1; i >= 0; i-- )
    {
        int pre = 0;
        if( i < n - 1 ) pre = fr[i + 1];
        if( s[i] == 0 )
        {
            if( i + c + 1 < n )
            {
                fr[i] = 1 + fr[i + c + 1];
            }
            else
            {
                fr[i] = 1;
            }
        }
        else
        {
            fr[i] = pre;
        }
    }

    if( fr[0] > k )
    {
        // k + 1日働けるので、どの日も休める
        return 0;
    }    

    // 左から一番働いたときの働いた累積日数
    bool flag = false;
    int left = fr[0];
    int r = 0;

    for( int i = 0; i < n; i++ )
    {
        bool restflag = ( r > 0);
        if( r > 0 ) r--;
        if( left != fr[i] )
        {
            flag = false;
            left = fr[i];
        }

        {
            if( !flag && !restflag )
            {
                if( s[i] == 0 )
                {
                    if( i + 1 >= n || fr[i + 1] != left )
                    {
                        cout << (i + 1) << endl;
                    }
                    flag = true;
                    r = c;
                }
            }
        }
    }
}