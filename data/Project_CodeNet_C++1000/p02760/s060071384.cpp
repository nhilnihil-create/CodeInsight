
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]

 int gcd(int a,int b){

   if(a%b == 0)
    return b;
   else
    return gcd(b,a%b);
 }

 long long numbers[500005];


 int main(){

 int a[3][3];
  int n,b;

  bool flag = 0;

  for(int i=0;i<9;i++){
        cin>>access(i);
  }

 long long Q; cin>>Q;

 while(Q--)
 {

  long long x;
   cin>>x;

   for(int j=0;j<9;j++){
     if(access(j) == x)
        access(j) = 0;
   }
 }

 for(int i=0;i<3;i++){

    if(a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0)
        flag = true;

    if(a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0)
        flag = true;
 }

 if(a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0)
    flag = true;
 if(a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0)
    flag = true;

 if(flag)
    cout<<"Yes"<<endl;
 else
    cout<<"No"<<endl;

 return 0;
 }
