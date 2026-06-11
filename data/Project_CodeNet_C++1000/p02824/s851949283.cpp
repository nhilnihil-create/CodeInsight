#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second     
#define fio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mp make_pair
#define int long long
using namespace std;
const int INF = 1e9;
const int MAX = 1e5+3;
int MOD = 1e9+7;
int n, m, v, p;
int arr[MAX];

bool is_pos(int mid)
{
   int temp_arr[MAX];
   memcpy(temp_arr, arr, n*sizeof(int));
   int ind = mid, tot = v*m;
   while(tot > 0 && ind >= 0)
   {
      temp_arr[ind] += m;
      tot -= m;
      ind--;
   }
   int to_be_equal = temp_arr[mid];
   ind = mid+1;
   while(tot > 0 && ind < n)
   {
      if(temp_arr[ind] >= to_be_equal)
         break;
      tot -= (to_be_equal-temp_arr[ind]);
      temp_arr[ind] = to_be_equal;
      ind++;
   }
   int last_ind = ind;
   if(tot > 0)
   {
      ind = n-1;
      while(tot > 0 && ind >= 0)
      {
         int to_add = min(m-(temp_arr[ind]-arr[ind]), tot);
         temp_arr[ind] += to_add;
         tot = tot - to_add;
         ind--;
      }
   }
   vector<pair<pair<int, int>, int> > dis;
   dis.pb({{-temp_arr[mid], -10}, mid});
   int curr_prior = 1;
   for(int i=0;i<n;i++)
   {
      if(i != mid){
         dis.pb({{-temp_arr[i], curr_prior}, i});
         curr_prior++;
      }
   } 
   sort(dis.begin(), dis.end());
   for(int i=0;i<p;i++)
   {
      if(dis[i].s == mid)
         return true;
   }

   return false;

}

int32_t main()
{
   cin>>n>>m>>v>>p;
   for(int i=0;i<n;i++)
      cin>>arr[i];
   sort(arr, arr+n);
   int ans = n, mid, low = 0, hi = n-1;
   while(low <= hi)
   {
      mid = (low+hi)/2;
      bool curr_pos = is_pos(mid);
      if(curr_pos)
      {
         ans = mid;
         hi = mid-1;
      }
      else
         low = mid+1;
   }

   cout<<n-ans;

}




         