#include<iostream>
using namespace std;

int main()
{
	int day[366];
	int month[12] = {0,31,60,91,121,152,182,213,244,274,305,335};
	int m,d;
	
	for(int i=0;i<366;++i)
		day[i] = i%7;
	
	while(cin >> m >> d){
		if(!m)
			break;

		switch(day[month[m-1] + d-1]){
		case 0:cout <<"Thursday"		<<endl;break;
		case 1:cout <<"Friday"			<<endl;break;
		case 2:cout <<"Saturday"		<<endl;break;
		case 3:cout <<"Sunday"			<<endl;break;
		case 4:cout <<"Monday"			<<endl;break;
		case 5:cout <<"Tuesday"			<<endl;break;
		case 6:cout <<"Wednesday"	<<endl;break;
		}

	}
	return 0;
}