#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
   int n;
   cin>>n;
   ll sum=0;
   for(int i=1;i<=n;i++){
      if(i%3!=0&&i%5!=0)
        sum+=i;
   }
   cout <<sum << endl;
}
