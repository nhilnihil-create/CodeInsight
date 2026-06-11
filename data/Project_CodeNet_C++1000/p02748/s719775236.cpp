#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int A,B,M;
    cin >> A >> B >> M;
    int a[A],b[B];
    rep(i,A)cin >> a[i];
    rep(i,B)cin >> b[i];
    int minA = 100000;
    int minB = 100000;
    rep(i,A)minA = min(a[i],minA);
    rep(i,B)minB = min(b[i],minB);
    int ans = minA + minB;
    rep(i,M){
        int x,y,c;
        cin >> x >> y >> c;
        int price = a[x-1] + b[y-1] - c;
        ans = min(price,ans);
    }
    cout << ans << endl;
    return 0;
}