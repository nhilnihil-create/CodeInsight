#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3E5+7;
ll arr[N];
ll crr[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        arr[x]++;
        crr[arr[x]]++;//这样可以让crr维护出现次数大于等于其下标的元素的个数。秒。。 
    }
    for(int i=1;i<=n;i++) crr[i]+=crr[i-1];
    for(int k=1;k<=n;k++){
        ll ans=0;
        ll left=0,right=n;
        while(left<=right){
            ll mid=(left+right)/2;
            if(k*mid<=crr[mid]){
                left=mid+1;
                ans=max(ans,mid);
            }
            else{
                right=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}