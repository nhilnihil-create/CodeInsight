#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,n;
    cin >> k >> n;

    vector<int> a(n);
    cin >> a.at(0);
    int sum = 0;
    int mx = 0;

    for(int i=1; i<n; i++){
        cin >> a.at(i);
        sum += a.at(i) -a.at(i-1);
        mx = max(a.at(i) - a.at(i-1), mx);
    } 

    sum += k - a.at(n-1) + a.at(0);
    mx = max(k - a.at(n-1) + a.at(0), mx);

    cout << sum - mx << endl;

    return 0;
}