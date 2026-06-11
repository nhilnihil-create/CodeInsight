#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    ll N,A,B;
    cin>>N>>A>>B;
    if((A-B)%2==0){
        cout<<abs(A-B)/2<<endl;
    }
    else{
     	ll p=0;
         ll k=0;
           ll c=A;
          ll d=B;
        if(A<B){
            p+=A-1;
            p++;
            B-=A;
          	A=0;
            p+=(B-A)/2;
            k+=N-d;
            k++;
            c+=N-d+1;
          	d=N;
            k+=(d-c)/2;
        }
        else if(A==B){
            p=N-A;
            k=A-1;
        }
        else{
            p+=B-1;
            p++;
            A-=B;
          	B=0;
            p+=(A-B)/2;
            k+=N-c;
            k++;
            d+=N-c+1;
          	c=N;
            k+=(c-d)/2;
        }
         cout<<min(p,k)<<endl;
    }
}
