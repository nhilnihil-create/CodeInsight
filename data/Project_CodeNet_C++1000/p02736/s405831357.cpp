#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int b[1000001];
int g(){
    int cnt=0;
}
int f(int x,int y){
    int cnt=0;
    if(b[x]-b[y]-b[x-y]==0)return 1;
    return 0;
}
int main(){
    int n;

    cin>>n;

    for(int i=0 ; i<n ; i++)scanf("%1d",&a[i]),a[i]--;
    for(int i=0 ; i<n ; i++){
        for(int j=2 ; j<=i  ; j*=2)b[i]+=i/j;
    }
    int s=0;
    for(int i=0 ; i<n ; i++)s+=a[i];
    if(s==0){
        cout<<0;
        return 0;
    }

    int t=0;
    int i;
    int cnt=0;
    for(i=0 ; i<n ; i++){
        t+=a[i]*f(n-1,i);
        t%=2;
        if(a[i]==1)cnt++;
    }
    if(t==1){
        cout<<1;
        return 0;
    }
    if(cnt){
        cout<<0;
        return 0;
    }

    for(i=0 ; i<n ; i++)a[i]/=2;
    s=0;
    for(int i=0 ; i<n ; i++)s+=a[i];
    if(s==0){
        cout<<0;
        return 0;
    }

    t=0;
    cnt=0;
    for(i=0 ; i<n ; i++){
        t+=a[i]*f(n-1,i);
        t%=2;
        if(a[i]==1)cnt++;
    }

    if(t==1){
        cout<<2;
        return 0;
    }
    cout<<0;
    return 0;
}
