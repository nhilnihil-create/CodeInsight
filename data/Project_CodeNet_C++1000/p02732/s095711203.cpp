#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n;
    cin>>n;
    map <long long,long long> b;
    long long a[n],ans=0;
    f(i,0,n){
        cin>>a[i];
        ans+=b[a[i]];
        b[a[i]]++;
    }
    f(i,0,n){
        cout<<ans-b[a[i]]+1<<endl;
    }
    return 0;
}
