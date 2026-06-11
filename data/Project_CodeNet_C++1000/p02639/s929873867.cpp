#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = INF;

int main (){
     
     vector<int>a(5);
     for(int i=0;i<5;i++){
     cin >> a.at(i);
     }
     
     for(int i=0;i<5;i++){
     if(a.at(i) == 0 )cout << i+1 << endl;
     }
     
     return 0;
}
