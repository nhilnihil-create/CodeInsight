
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int main(){

 int n; cin>>n;

 int a[n];
 for(int i=0;i<n;i++)
    cin>>a[i];

    int cnt=0,mini = 1e18;

 for(int i=0;i<n;i++)
 {
   mini = min(a[i],mini);
   if(mini == a[i])
        cnt++;
 }
  cout<<cnt<<endl;

 return 0;
}
