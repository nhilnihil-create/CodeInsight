#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
int main(){
    int n;
    cin >> n;
    ll L[n];
    rep(i,n){
        cin >> L[i];
    }
    int sum=0;
    rep(i,n-2){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
              if (L[i]==L[j] || L[i]==L[k] || L[j]==L[k]) continue;
                if(L[i]<L[j]+L[k] && L[j]<L[i]+L[k] && L[k]<L[i]+L[j]) {
                  sum++;
                }
            }
        }
    }
    cout << sum << endl;
}
