#include <iostream>
#include <string.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int a[N],b[N];

int main(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    while(k--){
    int flag=0;
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        b[max(i-a[i],0)]++;
        if(i+a[i]+1<=n-1)
        b[i+a[i]+1]--;
    }
    a[0]=b[0];
    for(int i=1;i<n;i++){
        b[i]+=b[i-1];
        a[i]=b[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]!=n){
            flag=1;
            break;
        }
    }
    if(flag==0) break;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}