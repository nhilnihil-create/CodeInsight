#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int calcdigit(int c){
	int res=1;
	while(1){
		if(c/10==0){
			break;
		}
		++res;
		c=c/10;
	}
	return res;

}
int main() {
    clock_t cTimeStart, cTimeEnd;
    cTimeStart = clock();           // 現在時刻
    int a,b;
   	while(cin>>a>>b){
	    cout<<calcdigit(a+b)<<endl;
   	}


    cTimeEnd = clock();           // 現在時刻
//    cout<< "処理時間:" <<(cTimeEnd - cTimeStart)/1000 << "[ms]" << endl;

	return 0;
}