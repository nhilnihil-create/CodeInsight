#include <iostream>

using namespace std;

int main(void)
{
	int a,d,n;

	int l;
	int count;
	int i1;

	int check;

	while(1){

		cin >> a;
		cin >> d;
		cin >> n;

		if (a==0 && d==0 && n==0) break;

		l = a;
		count = 0;
		check = 0;

		if(l==2) count++;
		else if(l!=1){
			for(i1=2;i1*i1<=l;i1++){
				if(l%i1==0){
					check = 1;
					break;
				}
			}
			if(check==0) count++;
		}

		

		while(count<n){
			l += d;
			check=0;

			if(l==2) count++;
			else{
				for(i1=2;i1*i1<=l;i1++){
					if(l%i1==0){
						check = 1;
						break;
					}
				}

				if(check==0) count++;
			}

		}

		cout << l << endl;
	}



	return 0;
}