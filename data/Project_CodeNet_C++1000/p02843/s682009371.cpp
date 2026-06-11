#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int num=x/100;
    if(x<=105*num)cout << 1;
    else cout << 0;
}