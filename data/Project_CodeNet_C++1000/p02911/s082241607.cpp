#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n,k);
    for(int i = 0; i < q; ++i){
        int x; cin >> x;
        a[--x]++;
    }
    for(int i = 0; i < n; ++i){
        if(a[i] <= q) puts("No");
        else puts("Yes");
    }
    return 0;
}