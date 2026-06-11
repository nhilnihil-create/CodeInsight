#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
double Deviation(int num,double seq){
	double sd;//standard deviation ?¨??????????
	sd=sqrt(seq/num);
	return sd;
}

double Sequence(int num,int score[],double ave){
	double sequence=0;
	for(int i=0;i<num;i++)sequence+=pow((score[i]-ave),2);
	return sequence;//?????°???

}

double Ave(int num,int score[]){//?????????
	double ave=0;
	for(int i=0;i<num;i++) ave+=score[i];
	ave/=num;
	return ave;

}

int main()
{
	int n;
	int s[1000];
	double deviation;
	double ave;
	double seq;
	while(1){
		cin>>n;
		if(n==0)break;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	ave=Ave(n,s);//?????????
	seq=Sequence(n,s,ave);//?????°????????¨???
	printf("%lf\n",Deviation(n,seq));
	}
	

	return 0;
}