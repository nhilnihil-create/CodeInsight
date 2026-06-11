#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t1,t2,a1,a2,b1,b2;cin>>t1>>t2>>a1>>a2>>b1>>b2;
    long long x = a1*t1+a2*t2,y=b1*t1+b2*t2;
    
    if(x==y){
        cout<<"infinity"<<endl;
        return 0;
    }
    //long long r = t1*a1-t1*b1;
    if((x>y&&a1<b1)||(x<y&&a1>b1)){
        long long A = (a1-b1)*t1;
        long long B = y-x;
        long long n=A/B;
        n*=2;
        if(A%B==0)n--;
        cout<<1+n<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;
}