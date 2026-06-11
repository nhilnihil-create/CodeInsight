#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define sort(v,n) sort(v,v+n);
#define vsort(v) sort(v.begin(),v.end());
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
typedef pair<int,int> p;
typedef pair<ll,ll> lp;
bool is_uruu(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
const ll MOD=1e9+7;
const double PI=acos(-1.0);
//---------------------------------------------------------------------------//
int n,m,a[110],b[110];
int main(){
        while(1) {
                cin>>n>>m;
                if(n==0) return 0;
                for(int i=0; i<n; i++) {
                        cin>>a[i];
                }
                for(int i=0; i<m; i++) {
                        cin>>b[i];
                }
                int abc=200;
                int amin,bmin;
                for(int i=0; i<n; i++) {
                        for(int j=0; j<m; j++) {
                                swap(a[i],b[j]);
                                int sum=0;
                                int sum2=0;
                                for(int k=0; k<n; k++) sum+=a[k];
                                for(int k=0; k<m; k++) sum2+=b[k];
                                swap(a[i],b[j]);
                                if(sum==sum2 && abs(a[i]-b[j])<abc) {
                                        abc=abs(a[i]-b[j]);
                                        amin=a[i];
                                        bmin=b[j];
                                }
                        }
                }
                if(abc!=200) cout<<amin<<" "<<bmin<<endl;
                else cout<< -1<<endl;
        }
}