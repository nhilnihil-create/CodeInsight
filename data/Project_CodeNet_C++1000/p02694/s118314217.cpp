#include<iostream>
#include<cmath>
using namespace std;

int main(){
    unsigned long long int X;
    cin >> X;
    unsigned long long int x=100;
    unsigned long long int ans=0;
    while(x < X){
        x += x/100;
        //x = floor(x);
        //cout << x << endl;
        ans++;
    }
    cout << ans << endl;
}