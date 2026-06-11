#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int N;
    cin >> N;
    int X[N];
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        sum += X[i];
    }
    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 0; i < N; i++) {
        ll t1 = (sum + N - 1) / N - X[i];
        ll t2 = sum / N - X[i];
        ans1 += t1 * t1;
        ans2 += t2 * t2;
    }
    cout << min(ans1, ans2) <<endl;
}