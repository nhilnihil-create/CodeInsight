#include <bits/stdc++.h>
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
    vector<int> s;
    int index = 0;
    int pre = 0;
    string sline;
    cin >> sline;
    for( int i = 0; i < sline.length(); i++ )
    {
        char c = sline[i];
        if( c == '<')
        {
            if( pre < 0 )
            {
                s.push_back(pre);
                pre = 0;
            }
            pre++;
        }
        else if( c == '>')
        {
            if( pre > 0 )
            {
                s.push_back(pre);
                pre = 0;
            }
            pre--;       
        }
        else
        {
            break;
        }
    }
    if( pre != 0 ) s.push_back(pre);

    int sl = s.size();
    long long i = 0;
    long long ans = 0;
    if (s[i] < 0)
    {
        int t = -s[i];
        while( t > 0 ) 
        {
            ans += t;
            t--;
        }
        i++;
    }

    while( i < sl )
    {
        {
            int t = 1;
            while( t < s[i] ) 
            {
                ans += t;
                t++;
            }
        }
        if ( i + 1 >= sl )
        {
            ans += s[i];
            break;
        }
        
        ans += max(s[i], -s[i + 1]);
        for( int t = -s[i + 1] - 1; t > 0; t--)
        {
            ans += t;
        }

        i += 2;
    }

    cout << ans;

    return 0;    
}