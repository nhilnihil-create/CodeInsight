#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    int64_t c=0, w;
    cin >> n >> k;
    priority_queue<int64_t> hs;
    for(int i=0; i<n; i++){
        cin >> w;
        hs.push(w);
    }
    if (k >= n){
        cout << c << '\n';
        return 0;
    }
    n -= k;
    for(int i=0; i<k; i++){
        hs.pop();
    }
    for(int i=0; i<n; i++){
        c += hs.top();
        hs.pop();
    }
    cout << c << '\n';
    return 0;
}