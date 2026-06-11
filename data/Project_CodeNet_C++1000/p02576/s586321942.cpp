#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int my_ceil(int a, int b){
    return a/b + (a%b > 0);
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x, t; cin >>n >>x >>t;

    cout <<my_ceil(n, x)*t <<endl;

    return 0;
}
