#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> ans(n);
    for(int i = 0; i < q; i++){
        int num;
        cin >> num;
        ans[num-1]++;
    }
    for(int i = 0; i < n; i++){
        if(ans[i] > (q - k)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}