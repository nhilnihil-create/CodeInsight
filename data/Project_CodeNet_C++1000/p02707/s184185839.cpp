#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n,i,j;
    cin >> n;

    int a[n+1];
    int b[200005] = {0};
    for(i=2; i<=n; i++){
        cin >> a[i];
        b[a[i]]++;
    }

    for(i=1; i<=n; i++){
        cout << b[i] << endl;
    }
    
    return 0;
}