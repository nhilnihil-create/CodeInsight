#include <bits/stdc++.h>
using namespace std;;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> sunuke(n);
    for (int i = 0; i < n; i++){
        sunuke[i] = 0;
    }
    int d;
    int s;
    for (int i = 0; i<k; i++){
        cin >> d;
        for (int j = 0; j < d; j++){
            cin >> s;
            sunuke[s-1]++;  
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (sunuke[i] == 0){
            ans++;
        }
    }
    cout << ans << endl;
}