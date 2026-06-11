#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;//左から k + 1 文字目以降の数字列を整数とみなした時の値an + 10an−1 + ... + 10n−k−1ak+1 を Tk
using vc = vector<char>;//Ti−1 == Tj (mod2019)の時に満たす
using vb = vector<bool>;
const int INFTY =2147483647;
int main(){
    string s;
    int ans=0,m[200005],a[2020]={};
    cin>>s;
    int n=s.length(),k=1;
    m[n]=0;
    a[0]++;
    for(int i=n-1;i>=0;i--){
        m[i]=(m[i+1]+(s[i]-'0')*k)%2019;
        k=(k*10)%2019;
        a[m[i]]++;
    }
    REP(i,2020){
        if(a[i]>=2) ans+=(a[i]*(a[i]-1))/2 ;
    }
    cout<<ans<<endl;
}
