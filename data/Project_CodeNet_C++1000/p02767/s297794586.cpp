#include <bits/stdc++.h>
using namespace std;
#define ref(i,c,n) for(int i = n;i<c;i++)

int main()
{
    int n;
    cin>>n;
    int arr[n],l = 100,r = 0,ans = 100000000;
    ref(i,n,0)
    {
        cin>>arr[i];
        l = min(arr[i],l);
        r = max(arr[i],r);
    }
    for(int i = l;i<=r;i++)
    {
        int temp = 0;
        ref(j,n,0)
        {
            temp += (arr[j]-i)*(arr[j]-i);
        }
        ans = min(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}