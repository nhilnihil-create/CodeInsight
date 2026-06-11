#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;

const int N=2e5+100;
const int mod=1e9+7;

int x[N],y[N];
int main()
{
   ios::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
   for(int i=1;i<=n;i++){
     cin>>x[i]>>y[i];
   }
   sort(x+1,x+1+n);
   sort(y+1,y+1+n);
   if(n&1){
    cout<<y[n/2+1]-x[n/2+1]+1<<endl;
   }
   else{
    cout<<y[n/2]+y[n/2+1]-x[n/2]-x[n/2+1]+1;
   }
  return 0;
}

