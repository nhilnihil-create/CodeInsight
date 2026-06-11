#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long N,a,b;
    cin >>N>>a>>b;
    if((b-a)%2==0){
        cout<<(b-a)/2<<endl;
    }
    else{
       long long C=min(b-1,N-a);
       long long A=((N-(a+(N-b+1)))/2)+N-b+1;
       long long B=(((b-(a-1+1))-1)/2)+a-1+1;
       long long D=min(A,B);
       cout << min(C,D)<<endl;
    }
}