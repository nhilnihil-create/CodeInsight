#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c=0;
    cin >> n;
    int a1[n], a2[n];

    for(int i=0; i<n; i++){
        cin >> a1[i];
        a2[i] = a1[i];
    }

    sort(a1, a1+n);

    for(int i=0; i<n; i++){
        if(a1[i] == a2[i]) c++;
    }

    if(c == n || c == n-2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
