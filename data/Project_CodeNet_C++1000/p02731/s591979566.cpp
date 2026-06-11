#include<bits/stdc++.h>
#define MAXN 1e5

using namespace std;

float l,a,b,c;

int main(){
    cin>>l;
    int q=l;
    a=l/3;
    b=l/3;
    c=l/3;
    if (q%3==1){
        c+=0.000001;
    }
    else if (q%3==2){
        a-=0.000001;
    }
    cout<<fixed<<setprecision(6)<<a*b*c<<endl;
}
