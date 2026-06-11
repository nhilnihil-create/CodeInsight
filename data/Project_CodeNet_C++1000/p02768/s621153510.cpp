/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>

long long int m = 1000000007;
using namespace std;

long long int pow2(long long int a, long long int b){
    long long int resp = 1;
    
    while(b!=0){
        if(b%2==1){
            resp = resp*a%m;
        }
        a = a*a%m;
        b /= 2;
    }
    
    return resp%m;
}

long long int fat(long long int maior, long long int menor){
    long long int resp=1;
    
    for(int i=menor;i<=maior;i++){
        resp*=i;
        resp=resp%m;
    }
    return resp;
}

long long int vs[200010];

int main(){
    vs[0]=1;
    
    for(int i=1;i<200005;i++){
        vs[i] = (vs[i-1]*i)%m;
    }

    long long int a,n,b,r,aux,auxb;
    
    cin >> n >> a >> b;
    
    r = pow2(2, n) - 1;
    
    aux = vs[a];
    aux = pow2(aux, m-2) * fat(n,n-a+1) % m;
    r+= m - aux;
    
    aux = vs[b];
    aux = pow2(aux, m-2) * fat(n,n-b+1) % m;
    r+= m - aux;

  
    cout << r%m << endl;
    
    return 0;
}
