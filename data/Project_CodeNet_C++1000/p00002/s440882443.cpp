#include <iostream>
using namespace std;

int main(){
	int a[200],b[200],sum[200],dight[200],line;
	for(int num=0;num<200;num++){
	dight[num]=0;a[num]=0;b[num]=0;
	}
	int fl=0;
	for(int num=0;num<200;num++){
	 // cout << "numA and numB"<< endl;
	 fl=0;
	 if(cin!=NULL){
	 cin >> a[num];
	 cin >> b[num];
	 }
	 else {
	 line=num-1;
	 break;
	 }
	 sum[num]=a[num]+b[num];
	 for(;fl!=1;){
	 if(sum[num]>=1){
	 sum[num]=sum[num]/10;
	 dight[num]++;
	 }
	 else fl=1;
    }
    }
    for(int num=0;num<line;num++){
    cout << dight[num]<< endl;
    }
  return 0;
}