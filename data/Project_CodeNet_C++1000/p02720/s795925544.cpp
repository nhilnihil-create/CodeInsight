#include<bits/stdc++.h>
#define P push
typedef long long ll;
using namespace std;
int main()
{
   queue<ll> lunlun; int k, j; ll x;
   cin>>k;
   for(j = 1; j <= 9; ++j) {lunlun.P(j); if(j == k) {cout<<lunlun.back(); return 0;}}; j--;
   while(1)
   {
       x = lunlun.front();
       if(x%10 != 0) {lunlun.P(10*x + x%10 - 1); j++; if(j == k) break;}
       lunlun.P(10*x + x%10); j++; if(j == k) break;
       if(x%10 != 9) {lunlun.P(10*x + x%10 + 1); j++; if(j == k) break;}
       lunlun.pop();
   }
   cout<<lunlun.back();
   return 0;
}
