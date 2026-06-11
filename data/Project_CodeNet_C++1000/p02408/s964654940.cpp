#include<iostream>
using namespace std;
int main(void)
{
	int a,n;
	bool card[52]; //S=0~12,H=13~25,C=26~38,D=39~51
	char c;

	for(int i=0 ; i<52 ; i++){
		card[i]=true;
	}

	cin >> n;

	for(int i=0 ; i<n ; i++){
		cin >> c >> a;

		switch(c){
		case 'S':
			card[a-1]=false;
			break;

		case 'H':
			card[a+12]=false;
			break;

		case 'C':
			card[a+25]=false;
			break;

		case 'D':
			card[a+38]=false;
			break;
		}
	}

	for(int i=0 ; i<52 ; i++){
		if(card[i]==true){
			switch(i/13){
			case 0:
				cout << "S " << i+1 << endl;
				break;

			case 1:
				cout << "H " << i-12 << endl;
				break;

			case 2:
				cout << "C " << i-25 << endl;
				break;

			case 3:
				cout << "D " << i-38 << endl;
				break;
			}
		}
	}
	return 0;
}