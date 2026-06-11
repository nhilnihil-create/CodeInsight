#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<int> ans(n-1,0);
    rep(i,n){
        for(int j = i+1;j < n;j++){
            int a = abs(i-j);
            int b = abs(i-x) + 1 + abs(j-y);
            int c = abs(i-y) + 1 + abs(j-x);
            int d = min(a,min(b,c));
            ans[d-1]++;
        }
    }
    rep(i,n-1)cout << ans[i] << endl;
    return 0;
}