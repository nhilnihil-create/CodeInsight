#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L
#define MOD 1e9+7

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    go(); 

    // code here
    int k;cin>>k;
    long long ans = 0;  
    for(int i = 1;i <=k; i++){
        for(int j = 1; j <=k ;j++){
            int cal = gcd(i,j);
            for(int l = 1; l <=k ;l++){
                ans += gcd(cal,l);
            }
        }
    }
    cout<<ans;

} 

