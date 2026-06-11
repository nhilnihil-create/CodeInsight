
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int cnt=0;
    rep(i,n){
        if(a[i]*100 >= 25*sum/m){
            cnt++;
        }
    }
    if(cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;

   

}