#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    long double a,b,x;
    cin>>a>>b>>x;
    if(x>=a*a*b/2){
        long double mother,son,son1,son2;
        mother=pow(a,3);
        son1=(double)2*pow(a,2)*b;
        son2=(double)2*x;
        son=son1-son2;
        long double ans=(double)atan(son/mother)/M_PI*180.0;
        cout<<fixed<<setprecision(15)<<ans<<endl;
        return 0;
    }
    else{
        long double c;
        c=(double)x/(a*b/2);
        long double hon;
        hon=(double)sqrt(pow(c,2)+pow(b,2));
        long double ans;
        ans=acos(c/hon)/M_PI*180.0;
        cout<<fixed<<setprecision(15)<<ans<<endl;
       
        return 0;
    }

}