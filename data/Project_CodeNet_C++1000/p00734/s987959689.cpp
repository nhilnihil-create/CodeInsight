#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(){
	int n, m,o;
	list<int> A,B;
	while (cin >> n >> m){
		if (n == 0 && m == 0){
			break;
		}
		for (size_t i = 0; i < n; i++)
		{
			cin >> o;
			A.push_back(o);
		}
		for (size_t i = 0; i < m; i++)
		{
			cin >> o;
			B.push_back(o);
		}
		A.sort();
		B.sort();
		int A_sum = 0, B_sum = 0;
		for (auto e : A){
			A_sum += e;
		}
		for (auto e : B){
			B_sum += e;
		}
		//cout << A_sum << " " << B_sum << endl;
		A_sum -= B_sum;
		int x=A.front(), y=B.front();
		A.pop_front();
		B.pop_front();
		bool f = 1;
		while (1){
			if ((x - y)*2 == A_sum){
				cout << x << " " << y << endl;
				f = 0;
				break;
			}
			else if ((x - y)*2 < A_sum ){
				if (A.empty()){
					break;
				}
				x = A.front();
				A.pop_front();
			}
			else if ((x - y)*2 > A_sum){
				if (B.empty()){
					break;
				}
				y = B.front();
				B.pop_front();
			}
			//cout << x << " " << y << endl;

		}
		if (f){
			cout << "-1" << endl;
		}
		A.clear();
		B.clear();
	}
}