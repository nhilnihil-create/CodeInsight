#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
 ll n,k,s;
 cin >> n >> k >> s;
 if(s==mm){
     rep(i,n){
         if(i<k)cout << mm << " ";
         else cout << mm-1 << " ";
     }
     cout << endl;
 }
 else if(s!=mm){
     rep(i,n){
         if(i<k)cout << s <<" ";
         else cout << mm <<" ";
     }
     cout << endl;
 }
} 
    