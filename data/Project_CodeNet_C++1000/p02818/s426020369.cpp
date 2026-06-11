#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
#define sqr(int) (int * int)
#define sqr3(int) (int * int * int)
#define pi M_PI
#define nl "\n"



 
  int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);
	 long long a, b, k;
     cin >> a >> b >> k;
     if(k <= a){
		 cout << a-k << " " << b;
	 }
	 else if(k <= a+b){
		 cout << 0 << " " << b - (k-a);
	 }
	 else{
		 cout << 0 << " " << 0;
	 }

	
}


	

