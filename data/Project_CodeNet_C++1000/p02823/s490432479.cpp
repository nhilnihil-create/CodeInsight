#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int main(){
    long long n,a,b;
    cin >> n >> a >> b;
    if((b-a)%2 == 0){
        cout << (b-a)/2 << endl;
        return 0; 
    }
    if(n-b > a-1){
        cout << (1+a+b-2)/2 << endl;
        return 0;
    }else{
        cout << (1+2*n-a-b)/2 << endl;
        return 0;
    }

}