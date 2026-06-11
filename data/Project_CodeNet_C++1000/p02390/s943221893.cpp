#include<iostream>

int main()
{
	int sec, min, hour;
	std::cin >> sec;
	min = sec / 60;
	hour = min / 60;
	min = min % 60;
	sec = sec % 60;
	std::cout << hour << ":" << min << ":" << sec << std::endl;

	return 0;
}