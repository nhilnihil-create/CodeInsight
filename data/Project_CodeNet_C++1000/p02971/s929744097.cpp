#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int idx1,idx2,xnum1 = 0,xnum2 = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(xnum1 < a[i]){
            xnum1 = a[i];
            idx1 = i;
        }
    }
    a[idx1] = 0;
    for (int i = 0; i < n; i++)
    {
        xnum2 = max(xnum2,a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i] != 0) cout << xnum1 << endl;
        else cout << xnum2 << endl;
    }
    
    return 0;
}