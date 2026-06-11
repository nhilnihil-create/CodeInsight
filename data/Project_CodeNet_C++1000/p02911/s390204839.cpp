#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(q);
    for(int i = 0; i < q; i++) cin >> a[i];
    vector<int> correctnum(n+1, 0);
    for(int i = 0; i < q; i++) correctnum[a[i]]++;
    for(int i = 1; i <= n; i++){
        if(k-q+correctnum[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}