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
    int n, k; cin >> n >> k;
    vector<long long>p(n,0);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    long long ns = 0;
    for(int i =0; i < k; i++){
        ns+=p[i];
    }
    cout << ns;
}