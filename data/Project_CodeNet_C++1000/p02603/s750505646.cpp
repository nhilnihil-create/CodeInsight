#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=2019;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    ll cnt=0, sum=1000;
    for(int i=0; i<N-1; i++){
        if(A[i+1] > A[i]){
            ll tmp=sum/A[i];
            cnt+=tmp;
            sum=sum-A[i]*tmp;
        }
        else{
            sum=sum+cnt*A[i];
            cnt=0;
        }
    }
    if(cnt > 0) sum=sum+cnt*A[N-1];
    cout << sum << endl;
    return 0;
}