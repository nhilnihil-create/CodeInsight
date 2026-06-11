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
using P =pair<int,int>;

int main(){
    ll n;
    cin>>n;
    ll i=2;
    
    while(1){
        
    if(n==2||n==3){
        cout<<n<<endl;
        return 0;
    }
    
    if(n%i==0){
    n++;
    i=2;
    continue;
    }
    
    
    if(i==n/2){
        cout<<n<<endl;
        return 0;
    }
    i++;
    }
    
}
