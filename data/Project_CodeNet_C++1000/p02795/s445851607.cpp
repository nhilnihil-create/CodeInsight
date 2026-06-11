#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main(){
	int h,w,n;
	cin >> h >> w >> n;
	int mx=max(h,w);
	int mi=min(h,w);
	
	int sum=0;
	int cnt=0;;
	for(int i=0;i<mi;i++){
		sum+=mx;
		cnt++;
		if(sum>=n)break;
	}
	cout << cnt << endl;
	
	return 0;
}

