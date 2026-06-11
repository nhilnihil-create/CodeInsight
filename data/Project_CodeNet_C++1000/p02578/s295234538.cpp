#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
 int a;
 cin >> a;
 vector<int> b(a);
 long long  ans = 0;
 for(int i = 0;i<a;i++){
     cin >> b[i];
 }
int maxnum =0;
for(int i= 0;i<a;i++){
    maxnum = max(maxnum,b[i]);
    int ai = maxnum;
    ans+=ai-b[i];
}
cout << ans << endl;

 return 0;
}