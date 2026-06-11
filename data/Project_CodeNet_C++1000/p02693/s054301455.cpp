#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)

int main(){
    ll K,A,B;
    cin>>K>>A>>B;
    while(A<=B){
        if(A%K==0){cout<<"OK"<<endl;return 0;}
        A++;
    }
    cout<<"NG"<<endl;
}

