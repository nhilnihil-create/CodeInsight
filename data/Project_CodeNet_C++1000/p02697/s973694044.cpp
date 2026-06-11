#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(n % 2 == 1){
        for(int i = 1; i <= m; i++){
            cout << i << ' ' << n - i + 1 << '\n';
        }
    }
    else{
        bool f = true;
        int l = 1, r = n;
        for(int i = 1; i <= m; i++){
            cout << l << ' ' << r << '\n';
            l++, r--;
            if(f && 4 * l > n){
                l++;
                f = false;
            }
        }
    }
    return 0;
}