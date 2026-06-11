    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n; cin >> n;
        int m = n % 1000;
        cout << (m ? 1000-m : m);
    }