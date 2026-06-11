#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    //fast ;
//#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#endif
    int a,b,c,k,s=0,i;
    cin >> a >> b >> c >> k ;
    s+=min(a,k);
    k-=min(a,k);
    k-=min(b,k);
    s-=min(c,k);
    cout << s <<"\n";
    return 0;
}
