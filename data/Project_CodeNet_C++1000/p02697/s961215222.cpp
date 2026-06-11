#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;

int main() {
    cin >> n >> m;
    if (n%2==1) {
        for (int i=1;i<=m;i++) {cout << i << " " << n-i << endl;}
    }
    else {
        int z=1;
        for (int i=1;i<=m;i++) {
                if (i*4>n) z=0;
                cout << i << " " << n-i+z << endl;
        }
    }

}
