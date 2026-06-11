#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define rep(i, n) for(i=0; i<n; i++)
using namespace std;
int main() {
    int i, n;
    cin >> n;
    vector<int> b;
    rep(i, n-1){
        int x;
        cin >> x;
        b.push_back(x);
    }
    //vector<int> a;
    //a[0] = b[0];
    int sum = b[0];
    for(i=1; i<n-1; i++){
        //a[i] = min(b[i], )
        sum += min(b[i], b[i-1]);
    }
    sum += b[n-2];
    cout << sum << endl;
    return 0;
}