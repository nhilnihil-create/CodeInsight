#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a[n];
    bool f=true;
    f(i,0,n){
        cin>>a[i];
    }
    for(int i=n-1;i>0;i--){
        if(a[i]<a[i-1]){
            a[i-1]--;
        }
    }
    f(i,0,n-1){
        if(a[i]>a[i+1]){
            f=false;
        }
    }
    if(f){
         cout<<"Yes"<<endl;
     }
     else{
         cout<<"No"<<endl;
     }
    return 0;
}
