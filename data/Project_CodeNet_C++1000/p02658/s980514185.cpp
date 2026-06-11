#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,x=0;
   cin>>n;
   ll a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
     if(a[i]==0)
        x++;
}
if(x>0)
    return cout << 0 << endl,0;
   ll pro=1;
   for(int i=0;i<n;i++){
    if(a[i]<=1000000000000000000/pro)
        pro*=a[i];
    else
        return cout <<-1 << endl,0;
    }
   cout << pro << endl;

    return 0;

}
