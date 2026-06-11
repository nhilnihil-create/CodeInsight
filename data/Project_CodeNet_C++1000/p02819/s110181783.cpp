

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

 int main(){

  int x;
  cin>>x;

 while(true){

  bool is_prime = true;

   for(int i=2,n=x;i<n;i++){
     if(x%i == 0){
        is_prime = false;
        break; }
   }

    if(is_prime)
    break;
    else
        x++;

 }

 cout<<x<<endl;

 return 0;
 }
