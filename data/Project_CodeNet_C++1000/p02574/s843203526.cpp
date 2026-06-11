#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
typedef long long ll;
const ll MAXN = 1e6+1;
ll factor[MAXN];

void slove(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i = 0; i < n; ++i){
        cin>>arr[i];
    }

    memset(factor,0,sizeof(factor));
    for(ll i = 2; i <= MAXN; ++i){
        if(factor[i] != 0) continue;
        factor[i] = i;
        for(ll j = i*i; j < MAXN; j += i){
            if(factor[j] == 0) factor[j] = i;
        }
    }// 求所有的数的最小质因子

    unordered_set<int> exists;
    bool pairwise = true;
    ll setwise = 0;
    for(int i = 0; i < n; ++i){
        vector<ll> curFact;
        ll now = arr[i];
        while (now > 1) {
            ll sml = factor[now];
            if (curFact.empty() || curFact.back() != sml) curFact.push_back(sml);
            now /= sml;
        }//求出该数的所有不同的质因子。
        
        for (auto f: curFact) {
            if (exists.count(f)) pairwise = false;
            exists.insert(f);
        }//如果该数所有的质因子与现有的质因子集合存在交集。
        setwise = __gcd(setwise,arr[i]);
    }
    
    if(pairwise){
        cout << "pairwise coprime\n";
    }else if(setwise == 1){
        cout << "setwise coprime\n";
    }else{
        cout << "not coprime\n";
    }

}
int main(){
    slove();
}
