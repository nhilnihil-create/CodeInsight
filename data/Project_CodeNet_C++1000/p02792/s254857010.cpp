#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N  =200005;

int n, a[11][11];
ll ans;

int f (int x){
while (x/10) x/=10;
return x;
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++){
        int first = f(i), last = i%10;
        a[first][last]++;
    }

    for (int i=1; i<=n; i++){
        int first = f(i), last = i%10;
        ans+= a[last][first];
    }
        cout << ans;
    return 0;
}
