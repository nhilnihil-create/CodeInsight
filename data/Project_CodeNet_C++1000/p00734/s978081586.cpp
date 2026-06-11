#include <iostream>

using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int taro[100];
	int hanako[100];
	int n, m;
	while(cin >> n >> m, n){
		for (int i = 0; i < n; i++)
			cin >> taro[i];
		for (int i = 0; i < m; i++)
			cin >> hanako[i];
		int sumtaro = 0, sumhanako = 0;
		for (int i = 0; i < n; i++)
			sumtaro += taro[i];
		for (int i = 0; i < m; i++)
			sumhanako += hanako[i];
		int diff = sumhanako - sumtaro;
		int pairsum = 1000;
		int extaro, exhanako;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) 
				if (diff == 2*(hanako[j] - taro[i]) )
					if (taro[i] + hanako[j] < pairsum) {
						extaro = taro[i];
						exhanako = hanako[j];
						pairsum = extaro + exhanako;
					}
		if (pairsum == 1000)
			cout << "-1" << endl;
		else
			cout << extaro << " " << exhanako << endl;
	}
	
	return 0;
}