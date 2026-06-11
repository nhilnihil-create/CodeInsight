#include<bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int main()
{
 fastIO();
 long long A,B,C,chose,ans, res ;
 cin>>A>>B>>C>>chose;
 //lin.
 if(A>=chose)
 {
 	cout<<chose<<endl;
 }
 else if((A+B)>=chose)
 {
 	cout<<A<<endl;
 }
 else
 {
 	ans = A-(chose-A-B);
 	cout<<ans <<endl;
 }

return 0;
}
