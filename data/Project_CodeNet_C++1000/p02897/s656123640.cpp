#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
#define sqr(int) (int * int)
#define sqr3(int) (int * int * int)
#define pi M_PI
#define nl "\n"



  float a,sum=0;
  int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);
	cin >> a;
	for(int i = 1; i<=a; i++){
		if(i%2 !=0 ){
			sum++;
		} 
	}
	
	
	printf("%.10f", sum/a);
	
	}

	
	


	

