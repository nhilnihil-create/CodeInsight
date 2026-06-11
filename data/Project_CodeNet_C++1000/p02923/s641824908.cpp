#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,ans=0,maxa=0;
    cin>>n;
    long long a[n];
    cin>>a[0];
    f(i,1,n){
        cin>>a[i];
        if(a[i]<=a[i-1]){
            ans++;
        }
        else{
            maxa=max(maxa,ans);
            ans=0;
        }
    }
    maxa=max(maxa,ans);
    cout<<maxa<<endl;
    return 0;
}
