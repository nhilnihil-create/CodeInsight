#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, l;
    cin >> n >> l;
    int a, b,  sum = 0;

    for (int i =1; i<=n; i++){
        sum += i;
    }

    a = n*(l - 1) + sum;
    b = (n - 1)*(l - 1) + sum;

    int min_num = 1e5, ans = 0;;
    for (int i=1; i<=n; i++){
        int temp = abs(a - (b - i));

        if (min_num > temp){
            min_num = temp;
            ans = b - i;
        }
    }

    cout << ans << endl;
    return 0;
}