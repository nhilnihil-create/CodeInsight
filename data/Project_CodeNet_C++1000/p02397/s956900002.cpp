#include<iostream>
#include<vector>

using namespace std;

struct my_pair
{
	int a;
	int b;
};

int main(void){
	vector<my_pair> input;

	while (1){
		int a,b;
		cin >> a>>b;

		if (a!=0||b!=0){
			my_pair mp;
			if (a < b){
				mp.a = a;
				mp.b = b;
			}
			else{
				mp.a = b;
				mp.b = a;
			}
			input.push_back(mp);
		}
		else{
			break;
		}
	}

	for (int i = 0; i < input.size(); i++){
		cout << input[i].a << " " << input[i].b << endl;
	}

	return 0;
}