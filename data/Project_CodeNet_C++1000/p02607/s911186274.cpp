#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i];
    
    int counter = 0;
    
    for (int i = 0; i < n; i += 2) {
        if (vec[i] % 2 == 1) ++counter;
        else continue;
    }
    
    cout << counter << "\n";
    
    return 0;
}
