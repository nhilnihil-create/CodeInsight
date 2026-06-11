#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, result = 0, outlet = 1;
    cin >> a >> b;
    while(outlet < b){
        outlet--;
        outlet += a;
        result++;
    }
    cout << result << "\n";
    return 0;
}
