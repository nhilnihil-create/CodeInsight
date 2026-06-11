#include<bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int main()
{
 fastIO();
 long long s , w , ans ;
 
 cin>>s>>w;
 
 if(w>=s)
 {
 	cout<<"unsafe"<<endl;
 	
 }
 else if(s>w)
 {
 	cout<<"safe" <<endl;
 }

return 0;
}
