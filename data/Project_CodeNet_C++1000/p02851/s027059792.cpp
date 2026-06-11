#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;

    vector<long long int> a(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] -= 1;
    }

    // cumulative sum
    for(int i=1; i<=n; i++){
        a[i] += a[i-1];
        a[i] %= k;
    }

    // solve
    long long int ans = 0;
    map<int, int> rem;
    queue<int> q;
    for(int i=0; i<n+1; i++){
        ans += rem[a[i]];
        rem[a[i]] += 1;
        q.push(a[i]);

        if(q.size() == k){
            rem[q.front()] -= 1;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}