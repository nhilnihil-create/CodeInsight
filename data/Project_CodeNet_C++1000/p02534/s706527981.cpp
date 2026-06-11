/* Ahmed Maher ( Acro_14 ) */
/*while(WA)try();*/
#include <bits/stdc++.h>
typedef long long ll;
const ll oo = 0x3f3f3f3f;
int const N = 3e5+5;
int const mod = 1e9+7;
using namespace std;
/*string Alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet="abcdefghijklmnopqrstuvwxyz";*/
long long fast_Power(int Base , int Expo){
    if(Expo == 0){
        return 1;
    }
    if(Expo == 1){
        return Base;
    }
    if(Expo % 2 == 0){
        long long ret = fast_Power(Base , Expo / 2);
        return ret * ret;
    } else {
        long long ret = fast_Power(Base , Expo - 1);
        return Base * ret;
    }
}
void solve(){
int n;
cin>>n;
while(n--)cout<<"ACL";
  }
int main()
{
    /*freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);*/
  int t;
	t=1;
     while(t--)
    {

		solve();

    }
	return 0;
}

//       int anss[t+1];
//            anss[j]=ans;
//     for(int j=1;j<=t;j++) printf("Case %d: %d\n",j,anss[j]);
