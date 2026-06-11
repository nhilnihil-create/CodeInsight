#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
int main(){
    int n,total=0,ans=0; cin >> n;
    vector<int> d(n);
    for(int i=0; i<n; i++) {
        cin >> d.at(i);
        total += d.at(i);
    }
    for(int i=0; i<n; i++) {
        total -= d.at(i);
        ans += total*d.at(i);
    }
    cout << ans << endl;
}