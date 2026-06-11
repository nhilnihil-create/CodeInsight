#include <bits/stdc++.h>
using namespace std;
int main(){
	while(true){
	int  hito,ten;
	
		cin>>hito;
		if(hito == 0)break;
		float hai[hito];
		float a = 0;
		float heikin;
		for(int i = 0;i<hito;i++){
			cin>>hai[i];
			
		}
		float zenbu = 0;
		for(int i = 0;i<hito;i++){
			zenbu += hai[i];
			
		}
		zenbu /=  hito;
		for(int i = 0;i<hito;i++){
			a += (hai[i]-zenbu)*(hai[i]-zenbu);
		}
		a /= hito;
	printf("%.10f\n",sqrt(a));
	}
	//return 0;
}
