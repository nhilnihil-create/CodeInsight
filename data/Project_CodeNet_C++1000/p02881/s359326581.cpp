#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long N;
    cin >>N;
    long long T=sqrt(N);
    long long stand=N-1;
     long long a;
    for(long long i=1;i<=T;i++){
        if(N%i==0){
         a=N/i;
         stand=min(stand,(a+i-2));
        }
    }
    cout <<stand <<endl;
}