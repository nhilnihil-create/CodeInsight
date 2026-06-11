#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> ostream& operator<<(ostream& os, const vector<T> arr){ for(int i = 0; i < (int)arr.size(); i++)cout << arr[i] << (i == (int)arr.size() -1 ? "" : " "); return os;}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        a[t - 1] = i + 1;
    }
    cout << a << endl;
}