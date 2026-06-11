#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int N;
    vector<ll> a;
    cin >> N;
    rep(i, N){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int cnt=0;
    rep(i, N){
        if((a[i] % 2) == 0) continue;
        if((i+1)%2 == 0) continue;
        cnt++;
    }
    cout << cnt << endl;
}