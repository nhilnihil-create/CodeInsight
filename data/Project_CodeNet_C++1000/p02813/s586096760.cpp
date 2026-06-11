#include <bits/stdc++.h>

#define ipair pair<int,int>
#define rep(i,n) for(i=0;i<n;i++)
#define repj(i,j,n) for(i=j;i<n;i++)

#define PB(a,i) (a).push_back(i)
#define ALL(a) (a).begin(),(a).end()
#define SIZE(a,n) (a).resize(n)
#define SORT(a) sort(ALL(a))
#define RSORT(a, type) sort(ALL(a),greater<type>())
#define MAPIN(a,i,j) (a).insert(make_pair(i,j))
#define PREC(n) setprecision(n)

#define OK(i) cout<<"OK "<<i<<endl
#define Yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define NO cout<<"NO"<<endl

using namespace std;

typedef unsigned long long lli;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > Matrix;

int main() {
    ll i,j,k,n,x,y,z;
    vll a,b;

	cin>>n;

    SIZE(a,n);
    SIZE(b,n);
    j=1;
    rep(i,n){
        cin>>a[i];
        j*=(i+1);
    }
    rep(i,n){
        cin>>b[i];
    }
    x=0;
    y=0;
    rep(i,n){
        k=n-i;
        x+=(j/k)*(a[i]-1);
        y+=(j/k)*(b[i]-1);
        j/=k;
        rep(z,n){
            if(a[i]<a[z])a[z]--;
            if(b[i]<b[z])b[z]--;
        }
    }
    cout<<abs(x-y)<<endl;

	return 0;
}
