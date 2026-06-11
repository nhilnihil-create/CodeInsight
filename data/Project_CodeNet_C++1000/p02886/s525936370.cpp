#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> takoyaki(n);
    
    for (int i = 0; i < n; i++) {
        cin >> takoyaki.at(i);
    }
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += takoyaki.at(i) * takoyaki.at(j);
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
