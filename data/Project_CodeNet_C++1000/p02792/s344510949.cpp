#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const ll MOD=1e9+7;

int main(){
    int N; cin >> N;
    ll res=0;
    for(int i=1; i<=N; i++){
        int a, b=i;
        a=i%10;
        while(b >= 10) b/=10;
        if(a == 0) continue;
        if(a == b) res++;
        int val=10*(a+1), c=0;
        while(val-10+b <= N){
            res+=(ll)pow(10, c);
            val*=10;
            c++;
        }
        for(int j=val/(a+1)*a+b; j<=N; j+=10){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}