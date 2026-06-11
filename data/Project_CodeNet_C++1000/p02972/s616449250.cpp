#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    vector<int> b(n,0);

    int m=0;
    for(int i=n-1;i>=0;i--){
        int tmp=0;
        for(int j=2*i+1;j<n;j+=i+1){
            if(b[j]==1) tmp++;
        }
        if(a[i]==0 && tmp%2==1){
            m++;
            b[i]=1;
        }
        else if(a[i]==1 && tmp%2==0){
            m++;
            b[i]=1;
        }
    }

    cout<<m<<endl;
    if(m==0) return 0;
    rep(i,n){
        if(b[i]==1) cout<<i+1<<" ";
    }
    cout<<endl;
}
