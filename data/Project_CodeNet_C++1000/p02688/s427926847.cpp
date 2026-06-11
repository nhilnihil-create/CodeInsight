#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int vis[102];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=n;i++)
    vis[i]=1;
   while(k--){
        int d;
        cin>>d;
        while(d--){
            int x;
            cin>>x;
            vis[x]++;
        }

   }
   int ans =0;
   for(int i=1;i<=n;i++){
    if(vis[i]<2)
        ans++;
   }
   cout << ans << endl;
    return 0;

}
