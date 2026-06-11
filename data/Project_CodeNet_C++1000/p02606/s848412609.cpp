#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

int coprime(int a,int b){

 int gcd;

  while(a!=0){
     gcd = a;
     a = b%a;
     b = gcd;
  }

  if(gcd == 1)
    return 1;
  else return 0;

}

// sorting the map elements by the second
// if the second value is equal then sorting is done on the first basis of the first element
bool compare(pair<int,int>p1, pair<int,int>p2){

    if(p1.second == p2.second)
        return p1.first < p2.first;

  return p1.second > p2.second;
 }

 // sorting the map when the first is string ans second is the integer
 bool sortbyval(pair<string,int>a, pair<string,int>b){

     if(a.second == b.second)
        return  a.first < b.first;

   return a.second < b.second;
 }




int main(){

 int l,r,d;
 int cnt=0;
 cin>>l>>r>>d;

 for(int i=l;i<=r;i++){

  if(i%d == 0)
    cnt++;
 }

  cout<<cnt<<endl;

return 0;
}
