#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int main(void)
{
    long long i, N, a[100001], b=0;

    cin >> N;
    
    for(i=1; i<=N; i++){
        cin >> a[i];
        b ^= a[i];
    }

    if(b==0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}