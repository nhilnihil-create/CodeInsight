#include <bits/stdc++.h>
using namespace std;
int main(){
	char number[200002];
	scanf("%s", number);
	int i = 0, sum = 0;
	while(number[i]!='\0'){
		int num = number[i] - 48;
		sum+=num;
		i++;
	}
	if(sum % 9 == 0){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}
