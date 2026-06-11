#include <iostream>
#include <vector>
using namespace std;

int main(void){ 
    int n, cnt = 0, max = 0;
    cin >> n;
    vector<int> a1(n), a2(n);
    for(int i=0; i<n; i++){
        cin >> a1[i];
        if(a1[i] > max) max = a1[i];
    }
    vector<int> count(max+1);
    for(int i=0; i<n; i++) count[a1[i]]++;
    for(int i=1; i<=max; i++) count[i] += count[i-1];
    for(int i=0; i<n; i++){
        a2[count[a1[i]]-1] = a1[i];
        count[a1[i]]--;
    }
    vector<bool> p(max+1);
    for(int i=0; i<n; i++){
        if(p[a2[i]]) continue;
        cnt++;
        if(i != n-1 && a2[i] == a2[i+1]) cnt--;
        for(int t=a2[i]; t<=max; t+=a2[i]) p[t] = true;
    }
    cout << cnt << '\n';
    return 0;
}