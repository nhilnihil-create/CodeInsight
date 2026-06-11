#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
    ///BISMILLAHIR RAHMANIR RAHIM
#define MAXN 1000000
bool prime[MAXN];
vector<int>v;

int main()
{

   //int t;
  // cin >> t;
   //int ex = 1;
   //while(t --)
   //{
       ll n;
       cin >> n;
       ll res = 0;
       for(int i=1;i<=n-1;i++){
            res += (n-1)/i;
       }
       cout<<res<<endl;

   //}
}
