#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              3000005
int arr[sz];
int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;
    cin>>n;
    for(i=1; i<=n; i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    reverse(arr+1,arr+n+1);

    ll sum=arr[1];
    for(i=2; i<=n/2; i++)sum+=(2*1LL*arr[i]);
    if(n%2){
        sum+=(arr[n/2+1]);
    }
    cout<<sum<<endl;


    return 0;
}
