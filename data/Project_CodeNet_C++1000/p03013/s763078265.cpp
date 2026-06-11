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
    int n,m;
    cin >> n>> m;
    vector<int>a(m);
    vector<ll>answer(n+10,0);
    REP(i,m){
        cin >> a[i];
        answer[a[i]]=-1;
    }

    answer[0]=1;

    REP(i,n){
        if(answer[i]==-1)continue;
        if(answer[i+1]!=-1){
            answer[i+1]=(answer[i+1]+answer[i])%MOD;
        }
        if(answer[i+2]!=-1){
            answer[i+2]=(answer[i+2]+answer[i])%MOD;
        }
    }

    cout << answer[n] << endl;

    return 0;
}