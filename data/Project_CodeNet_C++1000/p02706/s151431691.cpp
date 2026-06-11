#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,m,a[10000],cnt=0;
cin>>n>>m;
for(int i=1;i<=m;i++){
	cin>>a[i];
	cnt+=a[i];
}
if(n>=cnt)cout<<n-cnt;
else cout<<-1;
return 0;
}
