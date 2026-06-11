#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    //int n,vol,s[100];
    double a,n,vol,s[1000], avg;
    while(true){

        cin >>n;
        if(n==0) break;
        vol = 0;
        a = 0;
        for(int i = 0; i < n; i++){
            cin >>s[i];
            vol += s[i];
        }
        avg = vol / n;
        for(int i =0; i < n; i++){
            a += pow(s[i]-avg, 2.0);
        }
        a /= n;
        printf("%lf\n", sqrt(a));
    }
    return 0;
}
