#include<iostream>
using namespace std;
int main()
{
	int  n[1024], x[1024],a,s=0;
	for (int i = 0; i < 1024; i++){
		cin >> n[i] >> x[i];
		if (n[i] == 0&&x[i]==0){
			a = i;
			break;
		}
	}
	for (int i = 0; i < a; i++){
		for (int j=1; j < n[i]-1; j++){
			for (int k = j+1;k<n[i]; k++){
				for (int l = k+1;l<n[i]+1; l++){
					if (j + k + l == x[i]){
						s += 1;
					}
				}
			}
		}
		cout << s << endl;
		s = 0;
	}
	return 0;
}