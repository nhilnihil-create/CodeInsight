#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


//void warshall_floyd(int n){
//    for(int k=0;k<n;k++){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//            }
//        }
//    }
//}
//ll calc_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        ++res;
//        N /= 10;
//    }
//    return res;
//}
//ll sum_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        res += N % 10;
//        N /= 10;
//    }
//    return res;
//}

int main() {
    string s; int n ; cin >> s >> n;
    deque<char> ans(s.size());
    for(int i = 0;i < s.length();i++) ans[i] = s[i];
    int rev = 0;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        if(x == 1){
            rev = 1 - rev;
        }else{
            int f; char z;
            cin >> f >> z;f--;
            if (rev) f = 1 - f;
                
                if(f == 0){
                    ans.push_front(z);
                }else{
                    ans.push_back(z);
                }
            
        }
    }
    if(rev) reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout << x;
    }
}


