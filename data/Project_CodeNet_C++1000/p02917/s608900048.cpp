#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   vector<int> v(n-1);
   for(int i=0;i<n-1;i++)cin >> v[i];
   long sum = v[0] + v[n-2];
   for(int i=1;i<n-1;i++){
       sum += min(v[i-1],v[i]);
   }
   cout << sum << endl;
}
