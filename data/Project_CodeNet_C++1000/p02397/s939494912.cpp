#include<iostream>
using namespace std;

int main(){
int n,m;
while(1){
cin>>n>>m;
if(n==0&&m==0) break;
if(n>m) cout<<m<<" "<<n<<endl;
else if(n<m) cout<<n<<" "<<m<<endl;
else cout<<n<<" "<<m<<endl;
}
}