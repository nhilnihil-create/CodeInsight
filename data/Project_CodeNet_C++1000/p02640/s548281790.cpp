#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = INF;

int main (){
 int x , y;	cin >> x >> y ;
 
 if(2*x <= y && y <= 4*x && y % 2 == 0){
 cout << "Yes" << endl;
 return 0;
 }
 cout << "No" << endl;
}
