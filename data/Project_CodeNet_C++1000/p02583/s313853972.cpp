#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    long long int l[n];
    int ans = 0;
    for (int i = 0; i < n; ++i){cin >> l[i];}
    //sort(l, l+n);
    for (int i = 0; i < n-2; ++i){
        for (int j = i+1; j < n-1; ++j){
            for (int k = j+1; k < n; ++k){
                if(l[i] != l[j] && l[j] != l[k] && l[i] != l[k] && l[i]+l[j] > l[k] && l[i]+l[k] > l[j] && l[j]+l[k] > l[i]){
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}