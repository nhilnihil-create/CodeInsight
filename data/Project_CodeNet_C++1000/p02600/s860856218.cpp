#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int x;
    cin >> x;
    x = x / 200;
    switch(x) {
        case 2: printf("8"); break;
        case 3: printf("7"); break;
        case 4: printf("6"); break;
        case 5: printf("5"); break;
        case 6: printf("4"); break;
        case 7: printf("3"); break;
        case 8: printf("2"); break;
        case 9: printf("1"); break;
    }

    return 0;
}
