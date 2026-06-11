        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 200001;
const int MOD = 1000000007;
//
int fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
        signed main() {
    COMinit();
    int k,q;
    cin>>k>>q;
    int d[k];
    for(int i=0;i<k;i++)cin>>d[i];
    int z[k]={},sa[k]={};
    if(d[0]==0){z[0]=1;}
    sa[0]=d[0];
    for(int i=1;i<k;i++){
            z[i]=z[i-1];
            if(d[i]==0)z[i]++;
            sa[i]=sa[i-1]+d[i];
    }
    int n,x,m,n0,zeros,zx,al,ans,t[k];
    for(int i=0;i<q;i++){
            cin>>n>>x>>m;
            n--;
            if(d[0]==0)t[0]=0;
                else t[0]=(d[0]-1)/m;
                for(int i=1;i<k;i++)t[i]=t[i-1]+max(d[i]-1,0ll)/m;
                if(n%k){
                        zeros=z[n%k-1]+(n/k)*(z[k-1]);
                        cerr<<zeros<<endl;
                        zeros+=(sa[n%k-1]+(n/k)*sa[k-1]+x)/m;
                        cerr<<zeros<<endl;
                        zeros-=t[n%k-1]+(n/k)*t[k-1];
                        cerr<<zeros<<endl;

                }else {
                        zeros=(n/k)*(z[k-1]);
                        zeros+=(x+(n/k)*sa[k-1])/m;
                        zeros-=(n/k)*t[k-1];
                }
                zeros-=x/m;
                cout<<n-zeros<<endl;
                

           


    }
    
      }

        
