#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
#define sqr(int) (int * int)
#define sqr3(int) (int * int * int)
#define pi M_PI
#define nl "\n"



  int a,b,c,sum;
  int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);
	cin >> a >> c;
	for(int i = 0; i<a; i++){
		cin >> b;
		if(b >= c){
			sum++;
		}
	}
	
	cout << sum;
	
	
	}

	
	


	

