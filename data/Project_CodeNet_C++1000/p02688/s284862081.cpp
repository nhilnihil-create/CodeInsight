#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;
int main(){
    bool A[105];
    REP(i,105) A[i]=true;
    int n,k,d,ans,a;
    cin>>n>>k;
    ans=n;
    REP(i,k){
        cin>>d;
        REP(j,d){
            cin>>a;
            if(A[a]==true){
                ans--;
                A[a]=false;
            }
        }
    }
    cout<<ans<<endl;
}