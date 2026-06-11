/* 
* ID: juryc
* PROG: Papers, Please
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n;
vector<int> v(n);
for(int& i: v) cin>>i;
for(int i=0;i<n;i++) if(v[i]%2==0) if(v[i]%3&&v[i]%5) {cout<<"DENIED"<<endl; return 0 ; }
cout<<"APPROVED"<<endl;
}