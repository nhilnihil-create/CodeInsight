#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    int d;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        int x,y;
        double dd;
        cin>>x>>y;
        int a=abs(x);
        int b=abs(y);
        // temp=a>b?a:b;
        long long m=pow(a,2);
        dd = sqrt(m);
        if(dd<=(double)d){
            m += pow(b,2);
            dd = sqrt(m);
            if(dd<=(double)d){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}