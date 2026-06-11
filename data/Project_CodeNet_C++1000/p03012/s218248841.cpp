#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N{};
	cin >> N;

	vector<int> num(N);

	for (size_t i = 0;i < N;++i) {
		cin >> num.at(i);
	}

	size_t i = 0,j=N-1;
	int left = num.at(i), right = num.at(j);
	while (i!=j) {
		if (left >= right) {
			j--;
			if (i == j) {
				break;
			}
			else {
				right += num.at(j);
			}
		}
		else if(left < right){
			i++;
			if (i == j) {
				break;
			}
			else {
				left += num.at(i);
			}
		}
		if (i == j) {
			break;
		}
	}
	cout << abs(right - left);
}