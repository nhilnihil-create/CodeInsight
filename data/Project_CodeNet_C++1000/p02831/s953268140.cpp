#include <bits/stdc++.h>
using namespace std;

long long int lcm(long long int a,long long int b){
    if(a==1)    return 1;
    if(b==1)    return 1;
    long long int temp;
    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }
    while(a!=1){
        if(b%a==0){
            return a;
        }
        b=b%a;
        temp=a;
        a=b;
        b=temp;
    }
    return a;
}

int main() {
    long long int a,b;
    cin>>a >>b;
    long long int ans=lcm(a,b);
    ans=(a*b)/ans;
    cout << ans << endl;
    return 0;
}
