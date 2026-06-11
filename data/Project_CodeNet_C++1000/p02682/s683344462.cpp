#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    long long s = 0;
    if(a<=k){
        s+=a;
        k-=a;
    }
    else {
        s+=k;
        k=0;
    }

    if(k){
        if(b<=k){
            k=k-b;
        }
        else{
            k=0;
        }
        if(k){
            if(c<=k){
                s-=c;
            }
            else{
                s-=k;
            }
        }
    }


   // if(s<0) s=0;
    cout<<s;
}
