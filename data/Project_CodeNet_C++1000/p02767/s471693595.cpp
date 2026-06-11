#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N;
    cin >> N;
    vector<int> X (N+1, 0);

    int n_max=0;
    int n_min=101;
    int i, j;

    for(i=1;i<=N;i++){
        cin >> X[i];
        if(n_max <=X[i]){n_max = X[i];}
        if(n_min > X[i]){n_min = X[i];}
    }

    ll ans, ans_tmp;

    ans = 10000000000;
    for(i=n_min;i<=n_max;i++){
        ans_tmp = 0;
        for(j=1;j<=N;j++){
            ans_tmp += pow(X[j] - i, 2.0);  
        }
        if(ans > ans_tmp){ans = ans_tmp;}
    }

    cout << ans << endl;


    return 0;
}
