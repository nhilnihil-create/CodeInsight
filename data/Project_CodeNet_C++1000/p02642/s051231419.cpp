#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main(void){ 
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> p(1000001);
    for(int i=0; i<n; i++){
        if(!p[a[i]]){
            cnt++;
            if(i != n-1 && a[i] == a[i+1]) cnt--;
            int64_t now = a[i];
            while (now <= 1000000) {
                p[now] = 1;
                now += a[i];
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}