#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 998244353;

ll pow(ll a, ll b){
    ll ret=1;
    while(b>0){
        ret*=a;
        ret%=MOD;
        b--;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    vector<ll> cnt(N,0);
    int max_=0;
    for(int i=0; i<N; i++){
        int d;
        cin >> d;
        max_=max(max_,d);
        if(i==0 && d!=0){
            cout << 0 << endl;
            return 0;
        }else if(i!=0 && d==0){
            cout << 0 << endl;
            return 0;
        }

        cnt[d]++;
    }

    ll ans=1;
    for(int i=0; i<max_; i++){
        ans*=pow(cnt[i],cnt[i+1]);
        ans%=MOD;
    }
    cout << ans << endl;
}