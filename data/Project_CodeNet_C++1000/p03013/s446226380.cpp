#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    if (m != 0){
        for (int i = 0;i < m;i++){
        cin >> a[i];
        a[i]--;
        }
    }

    int c = 0;
    vector<bool> s(n,true);

    if (m != 0){
        for (int i = 0; i < n; i++){
            if (i == a[c]){
                s[i] = false;
                c++;
            }
        }
    }
    
    vector<long long> ans(n,0);

    for (int i = 0; i < n; i++){
        if (i == 0){
            if (s[i] == false){
                ans[i] = 0;
            }
            else{
                ans[i] = 1;
            }
        }
        else if (i == 1){
            if (s[1] == false){
                ans[i] = 0;
            }
            else{
                ans[i] = ans[i-1] + 1;
            }
        }
        else{
            if (s[i] == false){
                ans[i] = 0;
            }
            else{
                ans[i] = ans[i-1] + ans[i-2];
                ans[i] %= 1000000007;
            }
        }
    }

    cout << ans[n-1] << endl;
}
