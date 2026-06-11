#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2*1e5+50;
ll n,d,a,k,cumm[N],ans;
pair<ll,ll> arr[N];

int bin(int ind){
    int low=ind,high=n-1,mid,ans;
    while(low<=high){
        mid=low+(high-low)/2;
        if (arr[ind].first+(2*d)>=arr[mid].first){
            ans=mid;
            low=mid+1;
        }else
            high=mid-1;
    }
    return ans;
}

int main()
{
    scanf("%lld%lld%lld",&n,&d,&a);
    for (int i=0;i<n;i++)
        scanf("%lld%lld",&arr[i].first,&arr[i].second);
    sort(arr,arr+n);
    for (int i=0;i<n;i++){
        k+=cumm[i];
        arr[i].second-=k*a;
        if (arr[i].second>0){
            int num=bin(i);
            ans+=(arr[i].second+a-1)/a;
            cumm[num+1]-=(arr[i].second+a-1)/a;
            k+=(arr[i].second+a-1)/a;
        }
    }
    printf("%lld",ans);

    return 0;
}
