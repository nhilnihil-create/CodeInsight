#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,a[10],b[10],p[10];
int A,B;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) p[i]=i+1;
    int j=0;
    do{
        bool x=true,y=true;
        for(int i=0;i<n;i++){
            if(a[i]!=p[i]) x=false;
        }
        if(x) A=j;
        for(int i=0;i<n;i++){
            if(b[i]!=p[i]) y=false;
        }
        if(y) B=j;
        j++;
    } while(next_permutation(p,p+n));
    cout<<abs(A-B)<<endl;

}
