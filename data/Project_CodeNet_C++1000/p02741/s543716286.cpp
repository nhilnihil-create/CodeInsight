#include <bits/stdc++.h>

//$%U%$, $%D%$/$%M%$/$%Y%$, $%h%$:$%m%$:$%s%$

using namespace std;

#define inn(n)         int n; cin >> n;
typedef long long      ll;
typedef vector<int>    vi;
typedef pair<int, int> pi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

    inn(n);
    cout << arr[n-1];
    	
    return 0;
}

