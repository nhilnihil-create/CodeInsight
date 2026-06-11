#include <iostream>
using namespace std;

char judge(int mid, int last, int re){
	int total;
	total = mid + last;
	if(mid == -1 || last == -1){
		return 'F';
	}else if(80 <= total){
		return 'A';
	}else if(65 <= total && total < 80){
		return 'B';
	}else if(50 <= total && total < 65){
		return 'C';
	}else if(30 <= total && total < 50){
		if(50 <= re){
			return 'C';
		}
		return 'D';
	}else{
		return 'F';
	}
}

int main()
{
	int middle, last, re_ex;
	char record;
	while(true){
		cin >> middle >> last >> re_ex;
		if(middle == -1 && last == -1 && re_ex == -1){
			break;
		}
		record = judge(middle, last, re_ex);

		cout << record << endl;
	}

	return 0;
}