#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, K, C, ans=0, tmp=0;
string S;
vector<ll> v1, v2, A;

signed main(){
    cin >> N >> K >> C >> S;
    v1.resize(N,0);
    v2.resize(N,0);
    tmp = 0;
    for(int i=0;i<N;i++) {
        if(S[i]=='o') {
            v1[i]=1;
            i+=C;
            tmp++;
            if(tmp==K) break;
        }
    }
    tmp = 0;
    for(int i=0;i<N;i++) {
        if(S[N-1-i]=='o') {
            v2[N-1-i]=1;
            i+=C;
            tmp++;
            if(tmp==K) break;
        }
    }
    /*
    for(int i=0;i<N;i++) {
        cout << v1[i];
    }
    cout << endl;
    for(int i=0;i<N;i++) {
        cout << v2[i];
    }
    cout << endl;
    */
    ll ct1=0, ct2=0;
    for(int i=0;i<N;i++) {
        if(v1[i]>0) {
            v1[i] += ct1;
            ct1++;
        }
    }
    for(int i=0;i<N;i++) {
        if(v2[i]>0) {
            v2[i] += ct2;
            ct2++;
        }
    }
    for(int i=0;i<N;i++) {
        if(v1[i]==v2[i]&&v1[i]!=0) A.push_back(i+1);
    }
    for(int i=0;i<A.size();i++) {
        cout << A[i] << endl;
    }
    return 0;
}