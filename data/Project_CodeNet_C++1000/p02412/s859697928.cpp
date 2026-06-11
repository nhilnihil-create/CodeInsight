#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n=0,x=0;
	int counter;
	int i=0,j=0,k=0;

	while(1){
		cin >> n >> x;
		if(n==0&&x==0){
			break;
		}
		
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=j+1;k<=n;k++){
					if(i+j+k==x){
						counter +=1;
					}
				}
			}

		}
		cout << counter << endl;
		counter = 0;

	}
return 0;
}