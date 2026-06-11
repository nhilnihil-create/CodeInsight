#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
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
//    int ti = clock();
    int s, w;
    cin >> s >> w;
    if( w >= s )
    {
        cout << "unsafe";
    }
    else
    {
        cout << "safe";
    }
    


    //printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;    
}