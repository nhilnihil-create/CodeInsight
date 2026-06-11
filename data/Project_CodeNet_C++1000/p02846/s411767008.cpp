#include <bits/stdc++.h>
#define M ((ll)1e9+7)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi acos(-1)
typedef long long ll;
using namespace std;


void solve()
{
   ll t1,t2,a1,a2,b1,b2;
   cin>>t1>>t2>>a1>>a2>>b1>>b2;
       if((a1==b1&&a2>b2)||(a1<b1)){
       swap(a1,b1);
       swap(a2,b2);}
   ll d=(a1-b1)*t1+(a2-b2)*t2;
   //cout<<d<<endl;
   if(d==0)
   cout<<"infinity"<<endl;
   else if(d>0)
   cout<<"0"<<endl;
   else
   {
       //cout<<1<<endl;
       ll v=((a1-b1)*t1)/abs(d);
       if(a1==b1)
       cout<<1<<endl;
       else if(((a1-b1)*t1)%abs(d)==0)
       cout<<2*v<<endl;
       else
       cout<<2*v+1<<endl;
   }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
	return 0;
}