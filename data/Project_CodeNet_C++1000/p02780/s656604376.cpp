
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

double expect(int x){
    return (1+x)/2;
}

//累積和が使えそう
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    //累積和
    vector<double> sum(n+1);
    sum[0]=0;
    for(int i=0; i<n; i++){
        if(p[i]%2==0){
            sum[i+1] = sum[i] +p[i]/2 +0.5;
        }
        else if(p[i]%2==1){
            sum[i+1] = sum[i] +p[i]/2 + 1;
        }
    }
    double ans=0;
    for(int i=0; i<n-k+1; i++){
        double temp=sum[i+k]-sum[i];
        ans = max(ans,temp);
    }

    cout << setprecision(10) << ans << endl;

}