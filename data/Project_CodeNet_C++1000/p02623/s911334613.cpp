#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
 int n,m;
 long long k;
 cin >> n >> m >> k;
 vector<int>a(n);
 vector<int>b(m);
 long long t = 0;
 for(int i= 0;i<n;i++){
    cin >> a[i];
 }
for(int i= 0;i<m;i++){
   cin >> b[i];
   t+=b[i];
}
int ans = 0;
int j = m;
for(int i= 0;i<=n;i++){
   while (j>0&&t>k){
      --j;
      t-=b[j];
   }
   if(t>k) break;
   ans = max(ans,i+j);
   if(i==n) break;
   t +=a[i];
}
cout << ans << endl;
 return 0;
}