
 // jai shri ram
 //**********************************
 //**********************************
 //**********************************
 /**      BU_Excalibur      **/
/**  ABES college   **/

#include <bits/stdc++.h>
using namespace std;
#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define Toggle(n,i) (n^(1<<i))
#define Check(n,i) (n&(1<<i))
#define Set(n,i) (n|(1<<i))
#define Reset(n,i) (n&(~(1<<i)))
#define fo(a,x,y) for(int i=(x);i<=(y);++i){cout<<a[i]<<" ";}cout<<endl;
#define me(arr,val) memset(arr,val,sizeof arr)
#define inf 10e8
#define infl LLONG_MAX
#define mod 1000000007
#define f first
#define  g(t,a)  (get<a>(t))
#define pra(a) for(auto i:a){cout<<i<<endl;}
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 int main()
 {   IOS
     ll t,i,j;
     
     long long int n,e=INT_MAX,x=0,d=0,k,p,q,r,c,sum=1,l,ii;
       cin>>n;
       ll a[10000000]={0};
        for(i=2;i<=sqrt(1000000000000);i++)
        { for(j=i;j<=10000000;j+=i)
             a[j]++;
        }
        for(i=n;i<=10000000;i++)
         { if(a[i]==1)
            {cout<<i<<endl;
             break;
         }
        }
      }

