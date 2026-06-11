#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll maxx=0;
    ll a1=a*c;
    ll b1=a*d;
    ll c1=b*c;
    ll d1=b*d;
    cout<<max(max(a1,b1),max(c1,d1))<<endl;

	return 0;
}