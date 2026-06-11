#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll K,N;
ll ans;
string S;
ll a,b,d;
ll A[1000001];
 
 ll gcd(ll a, ll b)
 {
    if (a%b == 0)
    {
        return(b);
    }
    else
    {
        return(gcd(b, a%b));
    }
 }

 ll lcm(ll a, ll b)
 {
    return a * b / gcd(a, b);
 }
int main(){
    cin >> N>>K;
    for(int i=0;i<N;i++){
        if(i==0){
            cin >> a;
            a /= 2;
            ll aa = a;
            while(aa>=0){
                d++;
                if(aa%2==1){
                    break;
                }
                aa = aa/2;
            }
        }else{
            cin >> b;
            b /= 2;
            ll aa = b;
            ll k = 0;
            while(aa>=0){
                k++;
                if(aa%2==1){
                    break;
                }
                aa = aa/2;
            }
            if(k!=d){
                cout << 0 << endl;
                return 0;
            }
            ll c = lcm(a,b);
            if(c > K){
                cout << 0 << endl;
                return 0;
            }else{
                a = c;
            }
        }
        
    }
    cout << (K/a + 1)/2 << endl;
   
    
}
