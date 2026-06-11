#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> W(n);
    for(int i=0; i<n; i++) cin >> W[i];
    vector<int> S;

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += W[i];
        S.push_back(sum);
    }

    int a = sum;
    int min_div = sum;

    for(int i=0; i<n-1; i++) {
        a -= W[i];
        min_div = min(min_div,abs(a - S[i]));
    }
    cout << min_div << endl;
}

