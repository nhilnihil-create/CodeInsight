#include<bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    if (k == 1){
    cout << "0";
    return  0;
    }

    cout << n - k;
}
