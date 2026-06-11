#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int time;
	double m;
	int s[1000];
	double apow;
	while(true){
		cin>>time;
		if(time==0)break;
		apow=0;
		m=0;
		for(int i=0;i<time;++i){
			cin>>s[i];
			m+=s[i];
		}
		m/=(double)time;
		for(int i=0;i<time;++i){
			apow+=pow((double)s[i]-m,2.0);
		}
		cout<<sqrt(apow/(double)time)<<endl;
	}
	return 0;
}