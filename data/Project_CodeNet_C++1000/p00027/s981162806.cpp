#include <iostream>
#include <string>
using namespace std;

string data[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int m, d;
	while(cin >> m >> d && m != 0){

		for(int i = 0; i < m - 1; ++i){
			d += day[i];
		}

		d -= 1;
		cout << data[(d + 3) % 7] << endl;
	}

	return 0;
}