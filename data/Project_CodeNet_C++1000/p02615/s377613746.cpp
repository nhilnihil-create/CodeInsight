#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long int

#define mx 200005
int arr[mx];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n);

    ll ans=arr[n-1];
    int left=n-2;
    for(int i=n-2;i>=0;i--){
        if(left<=0) break;
        if(left>=2){
            left-=2;
            ans+=2*arr[i];
        }
        else{
            left--;
            ans+=arr[i];
        }

    }
    printf("%lld\n",ans);
    return 0;
}
