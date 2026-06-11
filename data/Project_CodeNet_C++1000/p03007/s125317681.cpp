#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n;cin>>n;
    ll a[100010],pl=0;
    rep(i,0,n){
        cin>>a[i];
        if(a[i]>=0)pl++;
    }
    sort(a,a+n);
    ll mi=n-pl,an=0;
    an-=a[0];
    rep(i,1,n-1){
        if(a[i]<0)an-=a[i];
        else an+=a[i];
    }
    an+=a[n-1];
    cout<<an<<endl;
    if(mi*pl!=0){
    rep(i,0,pl-1){
        cout<<a[mi-1]<<" "<<a[n-1-i]<<endl;
        a[mi-1]-=a[n-i-1];
    }
    cout<<a[mi]<<" "<<a[mi-1]<<endl;
    a[mi]-=a[mi-1];
    a[mi-1]=a[mi];
    rep(i,0,mi-1){
        cout<<a[mi-1]<<" "<<a[mi-2-i]<<endl;
        a[mi-1]-=a[mi-2-i];
    }
    }
    else if(mi==0){
        rep(i,0,n-2){
            cout<<a[0]<<" "<<a[n-1-i]<<endl;
            a[0]-=a[n-1-i];
        }
        cout<<a[1]<<" "<<a[0];
    }
    else if(pl==0){
        rep(i,0,n-1){
            cout<<a[n-1]<<" "<<a[n-2-i]<<endl;
            a[n-1]-=a[n-2-i];
        }
    }
    
}





