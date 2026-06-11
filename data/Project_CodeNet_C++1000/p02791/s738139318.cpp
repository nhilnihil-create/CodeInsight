#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,min,ans=0;
    cin>>n;
    long long a[n];
    f(i,0,n){
        cin>>a[i];
        if(i==0){
            ans++;
            min=a[i];
        }
        else{
            if(a[i]<min){
                ans++;
                min=a[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
