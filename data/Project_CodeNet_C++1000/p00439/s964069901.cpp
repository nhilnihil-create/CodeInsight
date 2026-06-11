#include<iostream>
#include<algorithm>
using namespace std;

int a[200000];
int n,l,s,maxn;

int main(){
    while(true){
        maxn=-100000000;
        s=0;
        cin>>n>>l;
        if(n==0 && l==0){break;}
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i<l){s+=a[i];}
        }
        maxn=s;
        for(int i=0;i<n-l;i++){
            s-=a[i];
            s+=a[i+l];
            maxn=max(s,maxn);
        }
        cout<<maxn<<endl;
    }
}