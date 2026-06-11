#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{    
    int n;
    cin >> n;
    
    vector<int> c(n);
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        c[a-1]++;
    }
    
    sort(c.rbegin(), c.rend());
    
    vector<int> d(n + 1);
    
    int j = n - 1;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        while(j >= 0 && c[j] <= i) {
            tot += c[j];
            j--;
        }
        
        d[i] = ((j + 1) * i + tot) / i;
    }
    
    for (int i = 1; i <= n; i++) {
        int ok = 0, ng = n + 1;
        
        while(ng - ok > 1) {
            int m = (ok + ng) / 2;
            
            if (d[m] >= i) {
                ok = m;   
            } else {
                ng = m;
            }
        }
        
        cout << ok << endl;
    }
}
