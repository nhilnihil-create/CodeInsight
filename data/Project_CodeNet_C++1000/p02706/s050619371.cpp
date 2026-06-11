#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    // n - study = ans

    int s = 0;
    for(int i = 0; i < m;i++)
        s += a[i];
        if (s > n)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << n - s << endl;
        }
    return 0;
}