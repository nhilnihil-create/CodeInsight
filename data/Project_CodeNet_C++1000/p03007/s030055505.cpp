#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N),P,M;
    vector<Pll> v;
    priority_queue<ll> que;
    rep(i,N){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll b = A[0];
    for(int i=1;i<N-1;i++){
        if(A[i] >= 0){
            v.push_back(Pll(b,A[i]));
            b -= A[i];
        }else{
            v.push_back(Pll(A[N-1],A[i]));
            A[N-1] -= A[i];
        }
    }
    v.push_back(Pll(A[N-1],b));
    A[N-1] -= b;
    cout << A[N-1] << endl;
    rep(i,N-1){
        cout << v[i].first <<" "<<v[i].second << endl;
    }
    /*
    if(N==2){
        cout << A[1]-A[0] << endl;
        cout << A[1] << " " << A[0] <<endl;
        return 0;
    }

    if(!(A[0] < 0 && 0 <= A[N-1])){
        if(A[0] >= 0){
            A[0] -= A[N-1];
            A.erase(A.begin()+N-1);
        }else{
            A[N-1] = A[0] - A[N-1];
            A.erase(A.begin()+0);
        }
    }
    rep(i,A.size()){
        if(A[i] >= 0){
            P.push_back(A[i]);
        }else{
            M.push_back(A[i]);
        }
    }
    ll ans = A[N-1];
    rep(i,A.size()-1){
        if(P.size() >= M.size()){
            v.push_back(Pll(A[i], ans));
            ans += A[i];
        }else{
            v.push_back(Pll(ans,A[i]));
            ans -= A[i];
        }
    }

    cout << ans << endl;
    rep(i,v.size()){
        cout << v[i].first << " " << v[i].second << endl;
    }*/
}
