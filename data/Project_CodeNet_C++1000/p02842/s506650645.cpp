#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	bool flag = false;
	int i;
	int lo=1, hi=50000, mid;
	while(lo<=hi){
	    mid = (lo+hi)/2;
	    if(int(mid*1.08)==n){
	        flag = true;
	        break;
	    }
	    else if(int(mid*1.08)>n){
	        hi = mid-1;
	    }
	    else{
	        lo = mid+1;
	    }
	}
	if(flag){
	    cout << mid << endl;
	}
	else{
	    cout << ":(" << endl;
	}
	return 0;
}
