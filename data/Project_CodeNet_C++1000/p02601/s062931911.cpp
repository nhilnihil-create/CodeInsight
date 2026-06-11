#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    int K;
    cin >>a>>b>>c>>K;
    int cnt=0;
    while (a>=b){
        b*=2;
        cnt++;
    }
    while (b>=c){
        c*=2;
        cnt++;
    }
    if (cnt<=K){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;

    }
    return 0;
}
