#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,a,b;
    cin>>n;
    a=n/100;
    b=n%100;
    if(b%5==0){
        b=b/5;
    }
    else{
        b=b/5+1;
    }
    if(a>=b){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
