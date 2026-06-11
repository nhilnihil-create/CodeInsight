#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
 
int main(){
    int N;cin>>N;
    ll a[N],x[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
        x[i]=0;
    }
    for(int i=1;i<=(N-1)/2;i++) x[0]+=a[2*i]-a[2*i-1];
    x[0]+=a[0];
    cout <<x[0]<<endl;
    for(int i=0;i<N-1;i++){
        x[i+1]=2*a[i]-x[i];
        cout << x[i+1] << endl;
    }
    
}