#include <iostream>

using namespace std;

int n;
int R[200000];
int maxdR, mdR, dR;

int main(void)
{
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> R[i];
	}
	
	for(int i=0;i<n-1;i++){
		dR = R[n-i-1]-R[n-i-2];
		if (i==0){
			mdR = dR;
			maxdR = mdR;
		}else{
			if (mdR>0){
				mdR += dR;
			}else{
				mdR = dR;
			}
			if (mdR>maxdR){
				maxdR = mdR;
			}
		}
	}
	
	cout << maxdR << endl;
	return 0;
}