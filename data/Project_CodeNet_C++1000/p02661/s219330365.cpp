#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   int n;
   cin >> n;
   vector<ll> a(n),b(n);
   for(int i=0; i<n; i++){
       cin >> a.at(i) >> b.at(i);
   }
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   ll left,right;
   if(n%2==0){
       left=(a.at(n/2-1)+a.at(n/2));
       right=(b.at(n/2-1)+b.at(n/2));
       cout << right-left+1 << endl;
   }
   else{
       left=a.at((n-1)/2);
       right=b.at((n-1)/2);
       cout << right-left+1 <<endl;
   }
}