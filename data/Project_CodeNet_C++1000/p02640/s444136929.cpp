#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    int x,y;
    cin >> x >> y;
    if((4*x-y)%2==0 && 0<=(4*x-y) && (4*x-y)<=2*x){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}