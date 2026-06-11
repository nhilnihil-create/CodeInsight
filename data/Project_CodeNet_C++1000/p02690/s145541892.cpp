#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1001];

int main() {
    int x;
    cin >> x;
    for (int i=0;i<=1000;i++) {
        ll z=i;
        for (int j=0;j<4;j++) z*=i;
        A[i]=z;
    }

    for (int i=0;i<=1000;i++) {
        for (int j=i;j<=1000;j++) {
            if (A[j]-A[i]==x) {
                cout << j << " " << i;
                return 0;
            }
            else if (A[j]+A[i]==x) {
                cout << j << " " << -i;
                return 0;
            }
        }
    }

}

