#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n

   ll x;
   cin>>x;
   ll a[4000];
   a[0]=100;
   for(int i=1;;i++){
    a[i]=a[i-1]+a[i-1]/100;
    if(a[i]>=x){
        cout << i << endl;
        return 0;
    }
   }
    return 0;

}
