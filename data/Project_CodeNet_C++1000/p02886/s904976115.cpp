#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int n, d[55];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j)continue;

            ans += d[i] * d[j];
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}