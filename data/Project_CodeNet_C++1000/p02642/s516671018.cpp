#include <iostream>

using namespace std;
int n , a[200010] , avail[1000009];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) avail[a[i]]++;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        avail[a[i]]--;
        bool check = false;
        for (int j = 1; j * j <= a[i]; j++){
            if (a[i] % j == 0)
                if (avail[j] > 0 || avail[a[i]/j] > 0) check = true;
        }
        if (check == false) ans++;
        avail[a[i]]++;
    }
    cout << ans;
    return 0;
}