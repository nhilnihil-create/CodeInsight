#include <iostream>
using namespace std;
int days(int m){
	if(m==1)
		return 0;
	else if(m==2)
		return days(1)+31;
	else if(m==3)
		return 29+days(2);
	else if(m==4)
		return 31+days(3);
	else if(m==5)
		return 30+days(4);
	else if(m==6)
		return 31+days(5);
	else if(m==7)
		return 30+days(6);
	else if(m==8)
		return 31+days(7);
	else if(m==9)
		return 31+days(8);
	else if(m==10)
		return 30+days(9);
	else if(m==11)
		return 31+days(10);
	else if(m==12)
	    return 30+days(11);
}
int main(){
	int m, d;
	while(cin>>m>>d){
		if(m==0)
			break;
		d+=days(m);
		if(d%7==1)
			cout<<"Thursday";
		else if(d%7==2)
			cout<<"Friday";
		else if(d%7==3)
			cout<<"Saturday";
		else if(d%7==4)
			cout<<"Sunday";
		else if(d%7==5)
			cout<<"Monday";
		else if(d%7==6)
			cout<<"Tuesday";
		else
			cout<<"Wednesday";
		cout<<endl;
	}
	return 0;
}
