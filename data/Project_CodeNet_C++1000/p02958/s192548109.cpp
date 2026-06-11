//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int n, i, flag = 0;
    cin >> n;
    vector<int> vec(n);
    for(i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for(i = 0; i < n; i++) {
        if(vec[i] != i + 1) flag++;
    }

    if(flag <= 2) cout << "YES" << "\n";
    else cout << "NO" << '\n';

    return 0;
}
