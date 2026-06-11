/*Points to be noted :
1)Don't be afraid to fail.
2)Never give up easily,keep trying.
3)Don't care about other ppl's progress.
4)Spend much time on each problem & keep trying. I WILL DO IT!💯


                                         MD RAKIBUL AZAD
                                         KOSAIY IN HSTU


*/
//
//        .--------------.
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'
//


#include<bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define intt                  long long int
#define ld                   long double
#define ull                  unsigned long long
#define pb                   push_back
#define mp                   make_pair
#define ff                   first
#define ss                   second
#define r0                   return 0;
#define tc                   int t;cin>>t;while(t--)
#define for0(i, n)           for (int i = 0; i < n; i++)
#define for1(i, n)           for (int i = 1; i <= n; i++)
#define loop(i,a,b)          for (int i = a; i < b; i++)
#define vi                   vector<int>
#define vii                  vector<long long int>
#define SORT(v)              sort(v.begin(),v.end());
#define PI                   3.1415926535897932384626433832795
#define mod                  1000000007
#define md                   998244353
#define inf                  1000000000000000 //1e15
#define gcd                  __gcd
#define lcm(a,b)             ((a)*(b))/gcd(a,b)
#define all(a)               (a).begin(),(a).end()
#define rall(a)              (a).rbegin(),(a).rend()
#define fifo                 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl                 "\n"
/*int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
int fp(int a,int b){
    if(b==0) return 1;
    int x=fp(a,b/2);
    x=(x*x)%mod;
    if(b&1) x=(x*a)%mod;
    return x;
}
int factorial(int n)
{
    int fact=1;
    for(int i=2;i<=n;i++)
    fact=fact*i;

    return fact;
}
int ncr(int n,int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}
void c_p_c()
{
    fifo;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}*/
  void solve()
   {
       string  a,b,x,y,z;
       cin>>x;
           if(x=="SAT")
           { cout<<"1"<<endl;
           }
           else if(x=="FRI")
           { cout<<"2"<<endl;
           }
           else if(x=="THU")
           { cout<<"3"<<endl;
           }
           else if(x=="WED")
           { cout<<"4"<<endl;
           }
           else if(x=="TUE")
           { cout<<"5"<<endl;
           }
           else if(x=="MON")
           { cout<<"6"<<endl;
           }
           else if(x=="SUN")
           { cout<<"7"<<endl;
           }




    }

 int main()
  {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	//cin >> t;
	//while(t--)
		solve();

}
