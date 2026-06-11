#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;


int main()
{
    ll t1,t2;cin>>t1>>t2;
    ll a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1>b1) {
        swap(a1,b1);
        swap(a2,b2);
    }
    ll len1=(a1-b1)*t1;
    ll len2=(a2-b2)*t2;
    ll ans=0;
    if(len1+len2==0){
         puts("infinity");
    }
    else if(len1+len2<0) {
        puts("0");
    }
    else {
          ans=(-len1)/(len1+len2);
         ans*=2;
         if((-len1)%(len1+len2)!=0) ans++;
         cout<<ans<<endl;
    }
    return 0;
}

