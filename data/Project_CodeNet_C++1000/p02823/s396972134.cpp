#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a,b;
    cin>>n>>a>>b;
    if ((b-a)%2==1) {
        cout<<min(a-1,n-b)+1+(b-a-1)/2<<endl;
    } else {
        cout<<(b-a)/2<<endl;
    }
}