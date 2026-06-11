#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> ball(N,0);
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    int ans = 0;
    for (int i = N - 1; i >= 0; i--){
        int num = N / (i + 1);
        int count = 0;
        for (int j = 1; j <= num; j++){
            count += ball[(i + 1) * j - 1];
        }
        if ((count % 2) != vec[i]){
            ball[i]++;
            ans++;
        }
    }
    cout << ans << endl;
    rep(i,N){
        if (ball[i] == 1) cout << i + 1 << " ";
    }
    if (ans >= 1){
        cout << endl;
    }
}
