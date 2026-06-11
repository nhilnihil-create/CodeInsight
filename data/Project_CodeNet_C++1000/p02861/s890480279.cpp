#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    long long N;cin>>N;
    long long X[N],Y[N];for(long long i=0;i<N;i++)cin>>X[i]>>Y[i];
    double length=0;
    for(long long i=0;i<N;i++){
        for(long long j=i+1;j<N;j++){
            length+=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
        }
    }
    length/=(N*(N-1)/2);
    cout<<setprecision(15)<<length*(N-1)<<endl;
    return 0;
}
