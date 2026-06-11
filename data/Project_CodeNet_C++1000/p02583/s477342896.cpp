#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<ll> L(n);
    for(int i = 0; i < n; i++){
        cin >> L[i];
    }

    int ans = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if(L[i] != L[j] && L[j] != L[k] && L[k] != L[i]){
                    if(L[i] + L[j] > L[k] && L[j] + L[k] > L[i] && L[i] + L[k] > L[j]){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}