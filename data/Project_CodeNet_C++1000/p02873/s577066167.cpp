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

 int gcd(int a,int b){

   if(a%b == 0)
    return b;
   else
    return gcd(b,a%b);

 }

 long long numbers[500005];

 int main(){

 string s;
 cin>>s;

  int n = s.length();

   numbers[0] = 0;

   long long sum=0;
   for(int i=0;i<n;i++)
   {
          if(s[i] == '<')
          numbers[i+1] = numbers[i]+1;
   }

   for(int i=n-1;i>=0;i--){
      if(s[i]== '>')
     {
         if(numbers[i] <= numbers[i+1] )
            numbers[i] = numbers[i+1]+1;
      }
   }


   for(int i=0;i<=n;i++)
    sum = sum+numbers[i];


   cout<<sum<<endl;


 return 0;
 }
