#include<iostream>
using namespace std;

int main(){
    long long a,b,c,d,ans;
    cin>>a>>b>>c>>d;

    if(a>=0){
        if(c>=0){
            ans=b*d;
        }else if(d<0){
            ans=a*d;
        }else{
            ans=b*d;
        }
    }else if(b<0){
        if(c>=0){
            ans=b*c;
        }else if(d<0){
            ans=a*c;
        }else{
            ans=a*c;
        }
    }else{
        if(c>=0){
            ans=b*d;
        }else if(d<0){
            ans=a*c;
        }else{
            long long p=a*c,m=b*d;
            if(p>=m){
                ans=p;
            }else{
                ans=m;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}