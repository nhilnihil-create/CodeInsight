#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main()
{
	int n;
	cin >> n;
	vector<unsigned int> a(n);
	rep(i, n){
		cin >> a[i];

	}

	

	sort(a.begin(), a.end());
	vector<unsigned int> b = a;

	a.erase(unique(a.begin(), a.end()), a.end());

	/*rep(i, a.size())
		cout << a[i];*/

	if(a.size() > 3){
		cout << "No";
		return 0;
	}

	bool flag = false;
	if(a.size() == 1){
		if(b[n-1] == 0)
			flag = true;

	}else if(a.size() == 2){
		
		if(n % 3 != 0){
			cout << "No";
			return 0;
		}
		if(a[0] == 0){
			if(b[n/3-1]==0 && b[n/3]==a[1])
				flag = true;
		}

	}else if(a. size() == 3){
		
		if(n % 3 != 0){
			cout << "No";
			return 0;
		}

		//printf("%d\n", ((a[0] ^ a[1]) ^ a[2]));
		if(((a[0] ^ a[1]) ^ a[2]) == 0){
			//cout << b[n/3-1] << b[n/3] <<  b[2*n/3-1] << b[2*n/3] << endl;
			if(b[n/3-1]==a[0] && b[n/3]==a[1] && b[2*n/3-1]==a[1] && b[2*n/3]==a[2])
				flag = true;
		}
	}

	if(flag) cout << "Yes";
	else cout << "No";
}
