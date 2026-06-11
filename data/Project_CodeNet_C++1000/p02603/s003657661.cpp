#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    ll money = 1000;
    ll stocks = 0;
    vector<ll>gain;
    cin >> n;
    vector<ll>a(n);
    REP(i,n)cin >> a[i];
    REP(i,n-1){
        int j = i;
        while(a[i]<a[i+1]){
            i++;
        }
        //購入
        stocks += (money/a[j]);
        money -= (money/a[j])*a[j];
        //売却
        money += stocks*=a[i];
        stocks = 0;
        gain.push_back(money);
    }
    SORT(gain);
    reverse(ALL(gain));
    cout << gain[0] << endl;
    return 0;  
}