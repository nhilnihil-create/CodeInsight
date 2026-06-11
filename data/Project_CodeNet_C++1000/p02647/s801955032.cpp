#include<bits/stdc++.h>
#define N 200050
#define M 200
#define int long long
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define coffee prince
#define sz(a) (int)a.size()
#define ll long long
#define SIZE N
#define MOD mod
using namespace std;
int n,k,ar[N],pr[N];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
   cin>>n>>k;
   for(int i=0;i<n;i++){
       cin>>ar[i];
   }
   for(int i=0;i<k;i++){
       int fl = 0;
       for(int i=0;i<n;i++){
           if(ar[i]!=n)fl = 1;
       }
       if(!fl)break;
       memset(pr,0,sizeof(pr));
       for(int i=0;i<n;i++){
           int l = max(0ll,i-ar[i]);
           int r = min(n+1,ar[i]+i+1);
           pr[l]++;
           pr[r]--;
       }
       ar[0] = pr[0];
       for(int i=1;i<n;i++){
           pr[i]+= pr[i-1];
           ar[i] = pr[i];
       }
   }
   for(int i=0;i<n;i++)
    cout<<ar[i]<<" ";
  	return 0;
}

