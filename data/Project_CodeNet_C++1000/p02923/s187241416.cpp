#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i;
    vector<int> h;
    for(i=0; i<n; i++){
        int x;
        cin >> x;
        h.push_back(x);
    }
    int tmp = 0, count = 0;
    for(i=1; i<n; i++){
        if(h[i]<=h[i-1]) tmp++;
        else{
            count = max(count, tmp);
            tmp = 0;
        }
    }
    cout << max(tmp, count) << endl;
    return 0;
}