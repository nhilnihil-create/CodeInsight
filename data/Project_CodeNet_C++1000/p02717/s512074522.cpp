#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    int x,y,z,temp;
    cin >> x >> y >> z;
    temp=x;
    x=z;
    z=y;
    y=temp;
    cout << x << " " << y << " " << z << endl;
}