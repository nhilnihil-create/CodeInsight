#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define filein freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);


void fun1(int* a,int* b){
    int sum=*a+*b;
    int dif=abs(*a-*b);
    //cout<<sum<<dif<<"\n";
    *a=sum;
    *b=dif;
}


int main() {


    long long n,m;
    cin>>n>>m;
    n%=m;
    long long t=abs(n-m);
    while (t<n){
        n=t;
        t=abs(n-m);
    }
    cout<<n;




}
