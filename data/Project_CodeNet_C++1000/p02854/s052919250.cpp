#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,a[200005],sum=0,l1=0,l,r,b=10000000000000000;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        l1+=a[i];
        if(abs(sum-2*l1)<b){
            b=abs(sum-2*l1);
            r=sum-l1;
            l=l1;
        }
    }
    cout<<abs(l-r)<<endl;
    return(0);
}