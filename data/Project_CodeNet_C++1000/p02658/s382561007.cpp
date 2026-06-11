#include<iostream>
using namespace std;
int main(){
    long long a[100000],b,n;
    int p=0,q=0;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    b=a[0];
    for(int i=0;i<n;i++){
        if(a[i]==0) {
            b=0;
            p=1;
            break;
            }
    }
    long long x=1000000000000000000;
    if(p==0) for (int i=0;i<n;i++){
        x=x/a[i];
        if(x<1) {
            q=1;
            break;
            }
    }
    if(p==0&&q==0) for(int i=1;i<n;i++){
        b=b*a[i];
    }
    if(p==1&&q==0)cout<<0;
    else if(p==0&&q==1) cout<<-1;
    else cout<<b;
    return 0;
}