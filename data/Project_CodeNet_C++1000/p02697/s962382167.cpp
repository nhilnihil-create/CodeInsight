#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;

int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int main()
{
    int ti = clock();

    int n, m;
    cin >> n >> m;
    pair<int, int> *ans = new pair<int, int>[m];
    int c1 = ( m + 1 ) / 2;
    int c2 = m / 2;
    int l = 1;
    int r = 2 * c1;
    for( int k = c1 - 1; k >= 0; k-- )
    {
        ans[k].first = l++;
        ans[k].second = r--; 
    }
    l = 2 * c1 + 1;
    r = l + 2 * c2;
    for( int k = c2 - 1; k >= 0; k-- )
    {
        ans[k + c1].first = l++;
        ans[k + c1].second = r--; 
    }

    for( int i = 0; i < m; i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    //printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;    
}