#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), F(N), D(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> F[i];
    sort(A.rbegin(), A.rend());
    sort(F.begin(), F.end());
    for(int i = 0; i < N; i++) D[i] = A[i]*F[i];
    ll Min = 0;
    ll Max = 0;
    for(int i = 0; i < N; i++) Max = max(Max, D[i]);
    Max++;
    ll cache;
    //cout  << " " << Min << " " << Max << endl;
    while(1){
        ll tag = (Min + Max)/2;
        //cout << tag << " " << Min << " " << Max << endl;
        if(tag == cache){
            cout << tag << endl;
            return 0;
        }
        ll k = K;
        bool flag = false;
        for(int i = 0; i < N; i++){
            ll c;
            if(D[i] <= tag) continue;
            if((D[i]-tag)%F[i] == 0) c = 0;
            else c = 1;
            ll num = (D[i] - tag)/F[i]+c;
            //cout << i << " " <<num << " " << tag << endl;
            k -= num;
            if(k < 0) {
                flag = true;
                break;
            }
        }
        if(flag) Min = tag+1;
        else Max = tag;
        cache = tag;
    }

}