#include <bits/stdc++.h>
using namespace std;

int main() {
    long a, b, m;
    cin >> a >> b >> m;
    
    int minrei = 100000;
    vector<int> reizoko(a);
    for (int i = 0; i < a; i++) {
        cin >> reizoko.at(i);
        minrei = min(minrei,reizoko.at(i));
    }
    
    int minden = 100000;
    vector<int> denshi(b);
    for (int i = 0; i < b; i++) {
        cin >> denshi.at(i);
        minden = min(minden,denshi.at(i));
    }
    
    long minsum = minrei + minden;
    
    for (int i = 0; i < m; i++) {
        long sum = 0;
        long x, y, c;
        cin >> x >> y >> c;
        
        sum = reizoko.at(x-1) + denshi.at(y-1) - c;
        minsum = min(minsum,sum);
    }
    
    
    cout << minsum << endl;
}
