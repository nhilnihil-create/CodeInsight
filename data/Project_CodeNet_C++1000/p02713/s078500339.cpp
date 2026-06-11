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
    ll k;
    cin>>k;
    ll sum=0;
    Rep(i,k+1){
        Rep(l,k+1){
            Rep(m,k+1){
                sum+=gcd(i,gcd(l,m));
            }
        }
    }
   cout<<sum<<endl;
}

