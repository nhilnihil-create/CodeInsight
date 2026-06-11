#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, start, end) for(int i = start; i < (int)(end); ++i)
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,1,n+1) cin >> a[i];
    vector<int> b(n+1);
    for(int i = n; 0 < i; i--){
        int state = 0;
        int cnt = i * 2;
        while(cnt < n + 1){
            state = state ^ b[cnt]; 
            cnt += i;
        }
        b[i] = state ^ a[i];
    }
    int sum = 0;
    rep(i,1,n+1){
        if(b[i]) sum++;
    }
    cout << sum << endl;
    rep(i,1,n+1){
        if(b[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}