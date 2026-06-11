#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> hen(n);

    if(k > (n - 1) * (n - 2) / 2) {
        cout << -1 << endl;
        return 0;
    }


    int m = n - 1;
    for(int i = 1; i < n; i++) {
        hen[0].push_back(i);
    }

    int t = (n - 1) * (n - 2) / 2;

    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(t == k)goto LAST;
            hen[i].push_back(j);
            m++;
            t--;
        }
    }
    LAST:;


    cout << m << endl;
    for(int i = 0; i < n; i++) {
        for(auto j : hen[i]) {
            cout << i + 1 << " " << j + 1 << endl;
        }
    }
}