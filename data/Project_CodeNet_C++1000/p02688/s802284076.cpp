#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> d(k);
    int b;
    for(int i = 0; i < k; i++){
        cin >> d[i];
        do{
            cin >> b;
            a[b - 1] += 1;
            d[i] -= 1;
        }while(d[i] > 0);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}