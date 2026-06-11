#include<iostream>
#include<fstream>
#include<list>

using namespace std;

int main(){

	ifstream fin("in.txt");

	typedef list<int>::iterator Iterator;

	list <int> stock;
	list<int> tmp;

	int n = 0, r = 0;
	int p = 0, c = 0;
	
	while (true){

		cin >> n >> r;
		if (n == 0 && r == 0)break;

		//?????????
		stock.clear();
		tmp.clear();
		for (int i = 1; i <= n; i++){
			stock.push_back(n - i + 1);
		}

		for (Iterator it = stock.begin(); it != stock.end();){
		//	cout << *it << " ";
			it++;
		}
		//cout << endl;

		//cout << stock.front() << endl;


		for (int i = 0; i < r; i++){

			cin >> p >> c;


			Iterator front = stock.begin();
			for (int i = 0; i < p - 1; i++){
				front++;
			}

			Iterator back = stock.begin();
			for (int i = 0; i < p + c - 1; i++){
				back++;
			}

			tmp.splice(tmp.begin(), stock, front, back);

			stock.splice(stock.begin(), tmp);

			for (Iterator it = stock.begin(); it != stock.end();){
			//	cout << *it << " ";
				it++;
			}
			//cout << endl;
		}

		cout << *stock.begin() << endl;
	}

	return 0;
}