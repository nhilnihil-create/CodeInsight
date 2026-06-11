#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    int a,b;
    cin>>a>>b;
    if(a==1){
        if(b==2) cout<<"3"<<endl;
        if(b==3) cout<<"2"<<endl;
    }
    if(a==2){
        if(b==3) cout<<"1"<<endl;
        if(b==1) cout<<"3"<<endl;
    }
    if(a==3){
        if(b==1) cout<<"2"<<endl;
        if(b==2) cout<<"1"<<endl;
    }
}