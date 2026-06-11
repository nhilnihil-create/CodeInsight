#include <bits/stdc++.h>
#include <map>
#include <iostream>

using namespace std;

int main() {
    long int n, k;
  
    cin >> n >> k;
  
    vector<int> a(n), d(n + 1);
    
    for(long int i=0;i<n;i++)
      cin >> a[i];
  
    for(long int i=0;i<n;i++) {
        d[i + 1] = d[i] + a[i];
        d[i + 1] %= k;
    }
    map<long int,long int> m;
  
    long int ans = 0;
  
    queue<long int> q;

for (long int i=0;i<=n;i++) {
        int t = (d[i] - i) % k;
      
        if (t < 0) t += k;
        
        ans += m[t];
        m[t]++;
        
        q.push(t);
        if (q.size() >= k) {
            m[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;
   
}
