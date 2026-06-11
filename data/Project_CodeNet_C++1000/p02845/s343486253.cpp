#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll che = 10e8 + 7;
    ll ans = 1;

    map<int, int> m;
    int cou = 0;
    m[0] = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            ans *= (3 - cou);
            cou++;
            m[a[i]]++;
        }else{
            ans *= m[a[i] - 1];
            m[a[i] - 1]--;
            auto itr = m.find(a[i]);
            if(itr == m.end()){
                m[a[i]] = 1;
            }else{
                m[a[i]]++;
            }
        }

        ans %= che;
    }

    cout << ans << endl;
}