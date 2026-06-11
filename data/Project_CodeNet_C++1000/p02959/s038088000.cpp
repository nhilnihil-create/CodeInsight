#include <bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(j, m) for (int j = 0; j <= (int)(m); j++)



int main(){

int n;
cin >> n;

vector<ll>a(n+1);
vector<ll>b(n);
rep(i,n+1) cin >> a[i];
rep(i,n) cin >> b[i];


ll ans = 0;

rep(i,n){
//勇者iが倒せる数が残っていないときは次の勇者へ
    if(b[i]==0) continue;

    //勇者iが倒せる数が残っているモンスターの数より少ないときは倒せるだけ倒す
    //都市iのモンスターを倒しきれないとき
   if(b[i]<= a[i]){
       ans += b[i];
       continue;
   }

    //勇者iが倒せる数が残っているモンスターの数より少ないときは倒せるだけ倒す
    //都市iのモンスターは倒せるが都市i+1のモンスターは倒しきれないとき
    if(b[i] <= a[i] + a[i+1]){
        ans += b[i];
        b[i] -= a[i];
        a[i+1] -= b[i];
        continue;
    }

    //勇者iが都市i, i+1のモンスターをすべて倒しきれるときはすべて倒す
        ans += a[i] + a[i+1];
        a[i+1] = 0;
   
    //a[i]も0にすべきだが、この変数はこの後使わないので省略

}
cout << ans << endl;
}