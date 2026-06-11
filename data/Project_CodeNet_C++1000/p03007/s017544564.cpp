#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll num;
        cin >> num;
        A.push_back(num);
    }
    sort(A.begin(), A.end());
    ll lv = A.back();
    ll mv = A[0];
    for(int i=1;i<A.size()-1;i++) {
        if(A[i]>=0) {
            //cout << mv << " " << A[i] << endl;
            mv -= A[i];
        }
        else {
            //cout << lv << " " << A[i] << endl;
            lv -= A[i];
        }
    }
    //cout << lv << " " << mv << endl;
    cout << lv-mv << endl;
    lv = A.back();
    mv = A[0];
    for(int i=1;i<A.size()-1;i++) {
        if(A[i]>=0) {
            cout << mv << " " << A[i] << endl;
            mv -= A[i];
        }
        else {
            cout << lv << " " << A[i] << endl;
            lv -= A[i];
        }
    }
    cout << lv << " " << mv << endl;
    //cout << lv-mv << endl;
    return 0;
}