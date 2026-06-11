#include <iostream>

int ans;
int count(int change)
{
	if(!change)
		return 0;
	if(change >= 500){
		ans += change / 500;
		count(change % 500);
	}
	else if(change >= 100){
		ans += change / 100;
		count(change % 100);
	}
	else if(change >= 50){
		ans += change / 50;
		count(change % 50);
	}
	else if(change >= 10){
		ans += change / 10;
		count(change % 10);
	}
	else if(change >= 5){
		ans += change / 5;
		count(change % 5);
	}
	else if(change >= 1){
		ans += change / 1;
		count(change % 1);
	}
}

int main()
{
	int pay;
	while(1){
		ans=0;
		std::cin >> pay;
		if(!pay)
			break;

		int change = 1000 - pay;

		count(change);

		std::cout << ans << std::endl;
	}
}