#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    long long ans = 1LL;
    for(int i = 0; i < n; i++){
        if(a[i] > 1000000000000000000LL/ans){
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
    }

    if (ans > 1000000000000000000LL){
        cout << -1 << endl;
    }else {
        cout << ans << endl;
    }
    return 0;
}

