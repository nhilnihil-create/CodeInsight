#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n,i;
    cin >> n;

    vector<int> B(n-1);

    cin >> B[0];
    int sum = B[0];

    for(i=1; i<n-1; i++){
        cin >> B[i];
        sum += min(B[i],B[i-1]);
    }

    sum += B[n-2];

    cout << sum << endl;

    return 0;
}