#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
 long long n,d;
 cin >> n >> d;
 vector<long long > x(n),y(n);
 int ans = 0;
 for(long i= 0;i<n;i++){
    cin >> x[i] >> y[i];
    if(sqrt(x[i]*x[i]+y[i]*y[i])<=d){
       ans ++;
    }
 }
 cout << ans << endl;
 return 0;
}