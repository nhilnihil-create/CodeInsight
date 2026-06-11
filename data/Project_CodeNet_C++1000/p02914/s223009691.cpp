#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
   FAST/**/
   
   ll n;
   cin>>n;
   
   ll arr[n];
   for(ll i=0;i<n;i++)
        cin>>arr[i];
   
   ll sum = 0;
   for(ll i=0;i<64;i++)
   {
       ll temp = (1LL<<i);
       ll cnt = 0;
       for(ll j=0;j<n;j++)
       {
           if((temp&arr[j]))
                cnt++;        
       }
       
       if(cnt%2 == 1)
       {
           sum+=temp;
           for(ll j=0;j<n;j++)
           {
               if((temp&arr[j]))
                    arr[j]-=temp;
           }
       }
   }
   
   ll id = 0;
   for(ll i=63;i>-1;i--)
   {
       ll mid = id;
       ll mel = LLONG_MIN;
       ll temp = (1LL<<i);
       for(ll j=id;j<n;j++)
       {
           if((temp&arr[j]) && mel<arr[j])
           {
               mel = arr[j];
               mid = j;
           }
       }
       
       if(mel == LLONG_MIN)
            continue;
       swap(arr[id],arr[mid]);
       mid = id;
       for(ll j=0;j<n;j++)
       {
           if(j!=mid&&(temp&arr[j]))
                arr[j] = arr[j]^arr[mid];
       }
       id++;
   }
   
   ll ans = 0;
   
   for(ll i=0;i<n;i++)
        ans^=arr[i];
   
   ans<<=1;
   sum+=ans;
   cout<<sum;
   
   return 0;
}