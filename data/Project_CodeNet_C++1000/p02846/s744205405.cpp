#include<iostream>
#include<cmath>
using namespace std;

int main() {
    long T1, T2;
    long A1, A2, B1, B2;
    cin>>T1>>T2;
    cin>>A1>>A2;
    cin>>B1>>B2;
    if((A1-B1)*T1+(A2-B2)*T2==0) cout<<"infinity"<<endl;
    else if(((A1-B1)*T1>0 & (A1-B1)*T1+(A2-B2)*T2>0) | ((A1-B1)*T1<0 & (A1-B1)*T1+(A2-B2)*T2<0))cout<<0<<endl;
    else {
        long a = (A1-B1)*T1+(A2-B2)*T2;
        if(abs(A1-B1)*T1%abs(a)==0) cout<<2*(abs(A1-B1)*T1/abs(a))<<endl;
        else cout<<2*(abs(A1-B1)*T1/abs(a))+1<<endl;
    }
}
