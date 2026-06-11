#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

bitset <sz> bst;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1, j=n-1; i<=m; i++, j--) {
        if(bst[j-i] || j-i==n+i-j) j--;
        bst[j-i] = bst[n+i-j] = 1;
        printf("%d %d\n", i, j);
    }
}
