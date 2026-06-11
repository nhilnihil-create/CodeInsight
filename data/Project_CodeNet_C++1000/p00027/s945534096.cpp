#include <iostream>
using namespace std;

int main() {
	int m,d;
	cin >> m >> d;
	
	while(m!=0 && d!=0){
		int days=0;
		days+=d;
		
		if(m==2)days+=31;
		else if(m==3)days+=60;
		else if(m==4)days+=91;
		else if(m==5)days+=121;
		else if(m==6)days+=152;
		else if(m==7)days+=182;
		else if(m==8)days+=213;
		else if(m==9)days+=244;
		else if(m==10)days+=274;
		else if(m==11)days+=305;
		else if(m==12)days+=335;
		
		days %= 7;
		
		switch(days){
		case 1: cout << "Thursday";break;
		case 2: cout << "Friday" ;break;
		case 3: cout << "Saturday";break;
		case 4: cout << "Sunday";break;
		case 5: cout<<"Monday";break;
		case 6: cout <<"Tuesday";break;
		case 0: cout <<"Wednesday";break;
		
		}
		cout << endl;
		
		cin >> m >> d;
	}
	return 0;
}