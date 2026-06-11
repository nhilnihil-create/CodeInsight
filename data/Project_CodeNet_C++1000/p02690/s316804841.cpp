#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_integer(double x){
    return floor(x)==x;
}

int main(){
    int X;
    cin >> X;

    ll A, B;
    int flag=0;
    for(int i=-200; i<200; i++){
        for(int j=-200; j<200; j++){
            if((i*i*i*i*i) - (j*j*j*j*j) == X){
                A=i;
                B=j;
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }
    if(X==1) cout << "0 -1" << endl; 
    else cout << A << " " << B << endl;
    return 0;
}