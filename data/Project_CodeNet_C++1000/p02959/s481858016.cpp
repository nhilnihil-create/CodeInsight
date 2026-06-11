#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int N;cin>>N;
    int a[N+1],b[N];
    for(int i=0;i<=N;i++)cin>>a[i];
    for(int i=0;i<N;i++)cin>>b[i];
    ll monster=0;

    for(int i=0;i<N;i++){
        int ans1=min(a[i],b[i]);
        int ans2=min(a[i+1],b[i]-ans1);
        monster+=ans1;
        monster+=ans2;
        a[i]-=ans1;
        a[i+1]-=ans2;
    }
    cout <<monster;


}