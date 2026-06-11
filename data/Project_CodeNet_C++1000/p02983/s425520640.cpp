#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

using namespace std;

int main()
{
    ll L, R, t, cnt;    cin >> L >> R;
    vector<int> check(2019,0);
    cnt = 0;
    for(ll i=L; i<R; i++){
        for(ll j=i+1; j<=R; j++){
            t = i*j%2019;
            check[t] = 1;
            cnt++;
            if(cnt > 2019*2019) break;
        }
        if(cnt > 2019*2019) break;
    }
    rep(i,2019){
        if(check[i] == 1){
            cout << i;
            return 0;
        }
    }
}