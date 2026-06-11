#include<iostream>
#include<algorithm>
#include<cstring>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
int a[maxn];
int main()
{
    ios;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll x=unique(a,a+n)-a;
    if(x==n)  cout<<"YES";
    else cout<<"NO";
}
