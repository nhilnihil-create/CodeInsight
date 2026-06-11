#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    if (n%2 == 0) printf("%.10f\n", 0.50000000);
    else printf("%.10f\n", (double)(n+1)/2/n);

    return 0;
}