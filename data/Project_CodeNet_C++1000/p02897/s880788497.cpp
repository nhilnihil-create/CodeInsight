#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int n;
    cin >> n;
    int m = n;
    double ans = 0;
    while(n > 0){
        if(n%2==1)ans++;
        n -= 1;
    }
    printf("%.10f\n",ans/m);
}