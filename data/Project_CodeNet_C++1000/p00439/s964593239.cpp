#include <iostream>
#include <queue>
using namespace std;
int main(){
	while(1){
		int n,k,num,max,tmp;
		queue<int> a;
		cin >> n >> k;
		if(!n&&!k) break;
		max=tmp=0;
		for(int i=0;i<k;i++){
			cin >> num;
			a.push(num);
			max+=num;
		}
		n-=k;
		tmp=max;
		while(n--){
			cin >> num;
			a.push(num);
			tmp+=a.back()-a.front();
			a.pop();
			if(max<tmp) max = tmp;
		}
		cout << max << endl;
	}
	return 0;
}