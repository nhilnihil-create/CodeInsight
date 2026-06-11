#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
   int n;
   cin>>n;
   vector<int> p(n);
   rep(i,n)cin>>p[i];
   int count=0;
   rep(i,n-2){
       if((p[i]<p[i+1]&&p[i+1]<p[i+2])||(p[i]>p[i+1]&&p[i+1]>p[i+2]))count++;
   }
   cout<<count<<endl;
}