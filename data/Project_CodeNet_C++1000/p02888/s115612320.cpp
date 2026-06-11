#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> L;

int main(){
    int n;
    cin >> n;
    L.resize(n);
    for(int i = 0; i < n; i++)cin >> L[i];

    sort(L.begin(), L.end());
    long long int ans = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+2; j < n; j++){
            int k = upper_bound(L.begin(), L.end(), L[j]-L[i]) - L.begin();
            k = max(k, i+1);
            ans += max(0, j-k);
        }
    }
    cout << ans << endl;
    return 0;
}