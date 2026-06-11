#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,t,a=0;
    cin>>n>>x>>t;
    while(n>0){
        n=n-x;
        a++;
    }
    std::cout << a*t << std::endl;
}