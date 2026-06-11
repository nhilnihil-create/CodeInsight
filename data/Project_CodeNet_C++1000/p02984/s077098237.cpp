#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, flag=0, tmp=0, mid=0;
vector<ll> A(MAXN, 0);

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll ng = -1;
    ll ok = 1000000001;
    while(1){
        //ll ngnum = ng*2;
        //ll oknum = ok*2;
        //cout << "ng : " << ng << " ok : " << ok << endl;
        //ll mid = (ng+ok)/2;
        //ll tmp = (ng+ok)/2;
        mid = (ng+ok)/2;
        tmp = (ng+ok)/2;
        for(int i=0;i<N-1;i++) {
            tmp=A[i]-tmp;
        }
        if(tmp+mid==A[N-1]) break;
        else if(tmp+mid>A[N-1]) {
            ok = mid;
        }
        else {
            ng = mid;
        }
        //cout << " mid : " << mid << " tmp : " << tmp << " A : " << A[N-1] << endl;
        //cout << endl;
    }
    tmp = mid;
    for(int i=0;i<N;i++) {
        if(i) cout << " ";
        cout << 2*tmp;
        tmp=A[i]-tmp;
    }
    return 0;
}