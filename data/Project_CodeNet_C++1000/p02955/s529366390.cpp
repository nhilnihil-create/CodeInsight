#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n,k,sum=0;
int count(int x,vector<int> a){
    vector<int> c(n);
    int s=0;
    for(int i=0;i<n;i++){
        s+=a[i]%x;
        c[i]=x-a[i]%x;
    }
    sort(c.begin(),c.end());
    int ret=0;
    for(int i=0;i<s/x;i++){
        ret+=c[i];
    }
    return ret;
}
int main(){
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)sum+=a[i];
    int ret=0;
    for(int i=1;i<=(int)sqrt(sum);i++){
        if(sum%i==0){
            if(count(i,a)<=k)ret=max(ret,i);
            if(count(sum/i,a)<=k)ret=max(ret,sum/i);
        }
    }
    cout<<ret<<endl;
}