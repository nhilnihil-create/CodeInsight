#include<iostream>
 
int main()
{
	const int dayMaxSum[13] = 
	{
		0,
		31,
		60,
		91,
		121,
		152,
		182,
		213,
		244,
		274,
		305,
		335,
		366
	};

	int month=1,day=0,daySum=0;//month=0で終了するため1で初期化

	while(std::cin >> month >> day && month!=0)
	{
		daySum = dayMaxSum[month-1]+day;

		switch(daySum%7)
		{
		case 1:
			std::cout << "Thursday";
			break;
		case 2:
			std::cout << "Friday";
			break;
		case 3:
			std::cout << "Saturday";
			break;
		case 4:
			std::cout << "Sunday";
			break;
		case 5:
			std::cout << "Monday";
			break;
		case 6:
			std::cout << "Tuesday";
			break;
		case 0:
			std::cout << "Wednesday";
			break;
		}
		std::cout << '\n';

		daySum=0;
	}
}