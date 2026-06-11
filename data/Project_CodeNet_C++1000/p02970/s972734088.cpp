// kyopro.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<map>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define For(i,N) for(ll i=0;i<N;i++)
int main()
{
    ll N;
    ll D;
    cin >> N >> D;
    ll s = 2 * D + 1;
    ll ans = N / s;
    if (N % s == 0)cout << ans;
    else cout << ans + 1;
}
