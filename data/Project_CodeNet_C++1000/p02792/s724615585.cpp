#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<lli> vi;
typedef vector<vector<lli>> vvi;
typedef pair<int,int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    int n;
    cin>>n;
    lli ans=0;
    vvi ma(9,(vi(9,0)));
    for(int i=1;i<=n;i++){
        if(i%10==0) continue;
        int l=log10(i);
        if(l==0){
            ma[i-1][i-1]+=1;
            continue;
        }
        else{
            int u,r,c;
            c=pow(10,l);
            u=i/c;
            r=i%10;
            ma.at(u-1).at(r-1)+=1;
        }
    }
    rep(i,9){
        rep(j,9){
        ans+=ma[i][j]*ma[j][i];
        }
    }
    out(ans);
}