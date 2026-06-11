#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){ 
    int n, cnt = 0, max = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] > max) max = a[i];
    }
    sort(a.begin(), a.end());
    vector<bool> p(max+1);
    for(int i=0; i<n; i++){
        if(!p[a[i]]){
            cnt++;
            if(i != n-1 && a[i] == a[i+1]) cnt--;
            for(int t=a[i]; t<=max; t+=a[i]) p[t] = true;
        }
    }
    cout << cnt << '\n';
    return 0;
}