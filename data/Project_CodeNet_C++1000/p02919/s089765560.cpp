/* while(!success_achieved())
      work_hard(); 

   code by:aman_ayush
  */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;
    ll arr[n],pos[n+1];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    multiset<ll> ms;
    ms.insert(-1);
    ms.insert(-1);
    ms.insert(n);
    ms.insert(n);
    ms.insert(pos[n]);
    ll cnt=0;
     for(ll i = n - 1; i >= 1; i--){
        auto itr = ms.upper_bound(pos[i]);
        ll r1 = *itr;
        itr++;
        ll r2 = *itr;
        for(int j = 0; j < 2; j++) itr--;
        ll l1 = *itr;
        itr--;
        ll l2 = *itr;
        cnt+= i * ((r2 - r1) * (pos[i] - l1) + (l1 - l2) * (r1 - pos[i]));
        ms.insert(pos[i]);
    }
    cout<<cnt<<"\n";
    return 0;
}
