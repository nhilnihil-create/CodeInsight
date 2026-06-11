#include <iostream>

using namespace std;

char alphabet(int remainder){
	if (remainder == 1){
		return 'a';
	}
	else if (remainder == 2){
		return 'b';
	}
	else if (remainder == 3){
		return 'c';
	}
	else if (remainder == 4){
		return 'd';
	}
	else if (remainder == 5){
		return 'e';
	}
	else if (remainder == 6){
		return 'f';	
	}
	else if (remainder == 7){
		return 'g';
	}
	else if (remainder == 8){
		return 'h';
	}
	else if (remainder == 9){
		return 'i';
	}
	else if (remainder == 10){
		return 'j';
	}
	else if (remainder == 11){
		return 'k';
	}
	else if (remainder == 12){
		return 'l';
	}
	else if (remainder == 13){
		return 'm';
	}
	else if (remainder == 14){
		return 'n';
	}
	else if (remainder == 15){
		return 'o';
	}
	else if (remainder == 16){
		return 'p';
	}
	else if (remainder == 17){
		return 'q';
	}
	else if (remainder == 18){
		return 'r';
	}
	else if (remainder == 19){
		return 's';
	}
	else if (remainder == 20){
		return 't';
	}
	else if (remainder == 21){
		return 'u';
	}
	else if (remainder == 22){
		return 'v';
	}
	else if (remainder == 23){
		return 'w';
	}
	else if (remainder == 24){
		return 'x';
	}
	else if (remainder == 25){
		return 'y';
	}
	else if (remainder == 26){
		return 'z';
	}
}

int main(){
	long long input;
	string ans = "";
	cin >> input;
	while(input){
		if(input%26==0){
			ans = 'z' + ans;
			input = input - 26;
		} else {
			int remainder = input % 26;
			char a = alphabet(remainder);
			ans = a + ans;		
		}
		input /= 26;
	}
	cout << ans << endl;
}	
