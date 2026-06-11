#include <iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
#define rep2(a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
string s;
cin>>s;
int n= s.length();
rep2(1,n){
   if((i&1 && s[i-1]=='L') || !(i&1) && s[i-1]=='R'){
       cout<<"No";
       return 0;
   }
}
cout<<"Yes";

}
