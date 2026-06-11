
#include <iostream>

using namespace std;

int main(){
	int n;
	int d[100100];

	cin >> n;

	for(int i=0; i<n; i++){
		d[i]=0;
	}

	int j;
	cin >> j;
	if(j!=0) {
		cout << "0" << endl;
		return 0;
	} else {
		d[0]+=1;
	}

	for(int i=1; i<n; i++){
		int j;
		cin >> j;
		d[j]+=1;
	}

	long int r=1;
	int s=1;
	if(d[0]==1){
		for(int i=1; i<n && s<n; i++){
			for(int j=0; j<d[i]; j++){
				r*=d[i-1];
				r%=998244353;
			}
			s+=d[i];
		}
	}else{
		r=0;
	}

	cout << r << endl;

	return 0;
}


