#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<iomanip>
using namespace std;

const double PI= acos(-1.0);

int gcd_func(int a, int b){
    return b? gcd_func(b, a%b) : a;
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x,n; cin >> x >> n;
    map<int,int>p;
    for(int i = 0; i < n; i++){
        int ipt;
        cin >> ipt;
        p[ipt] = 1;
    }
    int v1 = x, v2 = x;
    while(true){
        if(p.find(v1)==p.end()){
            cout << v1 << endl;
            break;
        }
        else if(p.find(v2) == p.end()){
            cout << v2 << endl;
            break;
        }
        v1--;
        v2++;
    }
    return 0;
}