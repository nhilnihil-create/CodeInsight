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
    sort(all(a));

    int sum=0;
    rep(i,n) sum+=abs(a[i]);
    if(a[0]>0) sum-=2*a[0];
    if(a[n-1]<0) sum+=2*a[n-1];
    cout<<sum<<endl;

    int acc=a[0];

    for(int i=1;i<n-1;i++){
        if(a[i]>=0){
            cout<<acc<<" "<<a[i]<<endl;
            acc-=a[i];
        }
    }

    cout<<a[n-1]<<" "<<acc<<endl;
    acc=a[n-1]-acc;

    for(int i=1;i<n-1;i++){
        if(a[i]<0){
            cout<<acc<<" "<<a[i]<<endl;
            acc-=a[i];
        }
    }


}