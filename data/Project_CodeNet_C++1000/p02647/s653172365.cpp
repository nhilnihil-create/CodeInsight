// 東京海上日動プログラミングコンテスト2020-C
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

vector<int> cur(200010);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    // int n=200000,k=200000;
    // rep(i,n){
    //     cur[i]=0;
    // }
    int n,k;
    cin>>n>>k;
    rep(i,n){
        cin>>cur[i];
    }
    //int count=0;
    rep(i,k){
        //count++;
        vector<int> imos(n+1,0);
        rep(j,n){
            int l=max(0,j-cur[j]);
            int r=min(n,j+cur[j]+1);
            imos[l]++,imos[r]--;
        }
        bool flag=true; //全部Nだったら終わり
        cur[0]=imos[0];
        if(cur[0]!=n) flag=false;
        for(int j=1;j<=n-1;j++){
            imos[j]+=imos[j-1];
            cur[j]=imos[j];
            if(cur[j]!=n) flag=false;
        }
        if(flag) break;
    }
    //cout<<count<<endl;
    rep(i,n) cout<<cur[i]<<" ";
    cout<<endl;
    return 0;
}