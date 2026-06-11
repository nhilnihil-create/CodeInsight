#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,mx=0;
    cin >> N;
    vector<int> H(N);
    for(int i=0;i<N;i++) {
        cin >> H[i];
    }
    for(int i=0;i<N;i++) {
        mx = max(H[i],mx);
        if(mx-H[i]>1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
