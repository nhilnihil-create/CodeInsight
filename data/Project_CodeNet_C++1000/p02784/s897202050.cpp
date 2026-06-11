#include<bits/stdc++.h>
using namespace std;
int main(){
int H,N;
  cin>>H>>N;
for(int i=0;i<N;i++){
	int A;
	cin>>A;
	H-=A;
}
if(H<=0)
  cout<<"Yes";
else 
  cout<<"No";

return 0;
}
