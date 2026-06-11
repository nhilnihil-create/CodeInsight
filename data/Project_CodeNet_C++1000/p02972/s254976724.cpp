#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200001;

ll N;
vector<ll> A(MAXN, 0), ans;

signed main(){
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
    }
    for(int i=N;i>=1;i--) {
        ll tmp=0;
        for(int j=i+i;j<=N;j+=i){
            tmp += A[j];
            tmp %= 2;
        }
        if(tmp!=A[i]) {
            A[i]=1;
            ans.push_back(i);
        }
        else A[i]=0;
    }
    cout << ans.size() << endl;
    for(int i=ans.size()-1;i>=0;i--) {
        if(i!=ans.size()-1) cout << " ";
        cout << ans[i];
    }
    return 0;
}