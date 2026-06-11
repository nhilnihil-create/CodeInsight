#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int arr[5] = {a, b, c, d, e};

    for (int i = 0; i < 5; i++){
        if(arr[i] == 0)
            cout << i+1;
    }

}

int main()
{
    solve();
    cout << "\n";
}
