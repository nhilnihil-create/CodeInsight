#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,f,ff,s=0;
    cin>>n;
    long long a[n];
    f(i,0,n){
        cin>>a[i];
        if(i==0){
            f=a[i];
            ff=i;
        }
        else{
            if(f<a[i]){
                f=a[i];
                ff=i;
            }
        }
    }
    f(i,0,n){
        if(i!=ff){
            if(a[i]>s){
                s=a[i];
            }
        }
    }
    f(i,0,n){
        if(i!=ff){
            cout<<f<<endl;
        }
        else{
            cout<<s<<endl;
        }
    }
    return 0;
}
