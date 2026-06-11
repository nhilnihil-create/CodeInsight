#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t n;
    int last;
    int cnt = 0;

    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++) {
        cin >> p[i];
    }

    last = p[0];
    for(int i=1;i<n-1;i++) {
        if(((last < p[i]) && (p[i] < p[i+1])) || ((last > p[i]) && (p[i] > p[i+1]))) {
            cnt++;
        } 
        last = p[i];
    }

    cout << cnt << endl;
    return 0;
}
