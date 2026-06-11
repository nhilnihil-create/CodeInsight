#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;




int main(){
    int n;cin >> n;
    vector<LL> a(n);
    vector<LL> x(n);
    LL sx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sx ^= a[i];
    }
    LL ans = 0;
    LL tx = 0;
    for (int i = 0; i < 60; i++) {
        if(sx>>i&1) ans += (1LL<<i);
    }
    for (int i = 0; i < n; i++) {
        x[i] = a[i];
        for (int k = 0; k < 60; k++) {
            if(sx>>k&1){
                x[i] &= ~(1LL<<k);
            }
        }
        tx ^= x[i];
    }
    sort(RALL(x));
    int index = 0; 
    for (int i = 60; i >= 0; i--) {
        LL maxInd = index; 
        LL maxEle = -LINF; 
        for (int j = index; j < n; j++) {
            if((x[j] & (1LL << i)) != 0 && x[j] > maxEle) maxEle = x[j], maxInd = j;
        }
        if (maxEle == -LINF) continue; 
        swap(x[index], x[maxInd]);
        maxInd = index;
        for (int j = 0; j < n; j++) {
            if(j!= maxInd && (x[j] & (1LL << i)) != 0) x[j] ^= x[maxInd];
        }
        index++;
    }
    LL res = 0; 
    for (int i = 0; i < n; i++) {
        res ^= x[i];
    }
    cout << ans + res + (tx ^ res) << endl;
    return 0;
}
