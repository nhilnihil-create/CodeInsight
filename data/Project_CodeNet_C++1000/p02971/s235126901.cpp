#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    int n;  cin >> n;
    vector<int> A(n),a(n);

    rep(i,n){
        cin >> A[i];
        a[i] = A[i];
    }
    sort(a.begin(),a.end(),greater<int>());

    rep(i,n){
        if(A[i]==a[0]){
            cout << a[1] << endl;
        }else{
            cout << a[0] << endl;
        }
    }

    return 0;
}