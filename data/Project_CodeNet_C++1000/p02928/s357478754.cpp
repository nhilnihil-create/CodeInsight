#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  fst first
#define  snd second
typedef pair<int,int> pii;
const ll mod=1e9+7;
const ll N = 2001;
ll a[N];
pii na[N];
ll k;
ll n;
ll res1=0,res2=0;
int bs(int low,int high,int idx){
int ans=n;
int target=na[idx].fst;
while(low<=high){
    int mid=(low+high)/2;
    pii temp=na[mid];
    if(temp.fst>target){
        ans=mid;high=mid-1;
    }
    else if(temp.fst<=target){
        low=mid+1;
    }
}
return ans;
}
int main(){
cin>>n>>k;
for(int i=0;i<n;i++){cin>>a[i];na[i]={a[i],i};}
multiset<ll> s;
for(int i=0;i<n;i++){s.insert(a[i]);auto it=upper_bound(s.begin(),s.end(),a[i]);if(it!=s.end()){ ll val=distance(s.begin(),it);res1+=s.size()-val;}}
sort(na,na+n);
for(int i=0;i<n;i++){
    res2+=n-bs(0,n,i);
}
ll fans=((((k*(k-1))/ (ll)2)%mod*res2)%mod+(k*res1)%mod)%mod;
cout<<fans<<endl;
return 0;
}
