#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    int n,k,s;
    cin >> n >> k >> s;
    vector<int> ans(n);
    if(s<1e9){
        for(int i=0;i<n;i++){
            if(i<k)
                ans[i] = s;
            else
                ans[i] = s+1;
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(i<k)
                ans[i] = s;
            else
                ans[i] = 1;
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}