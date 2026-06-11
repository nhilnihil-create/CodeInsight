#include<bits/stdc++.h>
#define lli long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test lli t;cin>>t;while(t--)
#define arrin lli n;cin>>n;lli a[n];for(lli i=0;i<n;i++)cin>>a[i]
#define floop for(lli i=0;i<n;i++)
#define mod 1000000007
#define defvec vector<lli>v
#define ub upper_bound
#define pb push_back
#define bs binary_search
#define endl '\n'
using namespace std;
lli merge(lli a[],lli l,lli mid,lli r)
{
  lli i=l,j=mid,k=0;
  lli temp[r-l+1];
  lli ans=0;
 while(i<mid&&j<=r)
{
   if(a[i]<=a[j])
{
   temp[k++]=a[i++];
}
else
{
   temp[k++]=a[j++];
   ans+=mid-i;
}
}
while(i<mid)
temp[k++]=a[i++];
while(j<=r)
temp[k++]=a[j++];
for(lli i=l,k=0;i<=r;i++,k++)
{
  a[i]=temp[k];
}
return ans;
}
lli merge_sort(lli a[],lli l,lli r)
{  lli count=0;
  if(l<r)
{
   lli mid=l+(r-l)/2;
   lli right_count=merge_sort(a,mid+1,r);
   lli left_count=merge_sort(a,l,mid);
   lli mergingcount=merge(a,l,mid+1,r);
   return right_count+left_count+mergingcount;
}
return count;
}

int main()
{  
  lli n;
  cin>>n;
  lli a[n];
  for(lli i=0;i<n;i++)
  cin>>a[i];
  sort(a,a+n);
  double ans=0;
  double flag=a[0];
  for(lli i=1;i<n;i++)
  {   
      
          flag=(flag+a[i])/2*(1.0);
         
  }
  cout<<flag<<endl;
}