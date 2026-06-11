#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vll A(N);
    bool p = true;
    bool m = true;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(A[i]>=0){m = false;}
        else{p = false;}
    }
    if(N == 2){
        cout << max(A[0], A[1]) - min(A[0], A[1]) << endl;
        cout << max(A[0], A[1]) << " " << min(A[0], A[1]);
    }
    else{
    if(p == true){
        sort(A.begin(),A.end());
        ll ans = 0;
        for(int i=1; i<N; i++){
            ans+=A[i];
        }
        ans -= A[0];
        cout << ans << endl; cout << A[0] << " " << A[1] << endl;
        ll k = A[0] - A[1];
        for(int i=2; i<N-1; i++){
            cout << k << " " << A[i] << endl;
            k = k - A[i];
        }
        cout << A[N-1] << " " << k;
    }
    else if(m == true){
        sort(A.begin(),A.end());
        ll ans = 0;
        for(int i=0; i<N-1; i++){
            ans -= A[i];
        }
        ans += A[N-1];
        cout << ans << endl;
        cout << A[N-1] << " " << A[0] << endl;
        ll k = A[N-1] - A[0];
        for(int i=1; i<N-1; i++){
            cout << k << " " << A[i] << endl;
            k = k - A[i];
        }
    }
    else{
        sort(A.begin(),A.end());
        ll c;
        for(int i=0; i<N-1; i++){
            if(A[i]<0&&A[i+1]>=0){c = i;}
        }
        ll ans = 0;
        ll minus =0;
        for(int i=0; i<N; i++){
            ans += abs(A[i]);
            if(A[i] < 0){minus++;}
        }
        cout << ans << endl;
        ll k = A[N-1];
        for(int i=0; i<minus-1; i++){
            cout << k << " " << A[i] << endl;
            k = k -A[i];
        }
        ll l = A[c];
        for(int i=0; i<N-minus-1; i++){
            cout << l << " " << A[c+i+1] << endl;
            l = l - A[c+i+1];
        }
        cout << k << " " << l;
    }
    }
}