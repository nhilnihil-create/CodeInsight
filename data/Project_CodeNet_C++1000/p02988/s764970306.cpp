#include <bits/stdc++.h>
using namespace std;

int main() {
 int n,cnt=0;cin >> n;
 vector<int> p(n);
 for(int i=0;i<n;i++){
   cin >> p[i];
 }
 vector<int> num(3);
   for(int i=1;i<n-1;i++){
    num[0]=p[i-1];
    num[1]=p[i];
    num[2]=p[i+1];
    sort(num.begin(),num.end());

    if(num[1]==p[i])cnt++;
   }
   cout << cnt << endl;

}
