#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const int shokin[3] = {300000,200000,100000};

int main(){
	int X,Y;
	cin >> X >> Y;
	if(1<=X && X<=3 && 1<=Y && Y<=3){
		if(X==1 && Y==1){
			cout << 300000*2 + 400000 << endl;
		}else{
			cout << shokin[X-1] + shokin[Y-1] << endl;
		}
	} else if (X>3 && 1<= Y && Y<=3){
		cout << shokin[Y-1] << endl;
	} else if (Y>3 && 1<=X && X<=3){
		cout << shokin[X-1] << endl;
	}else{
		cout << 0 << endl;
	}
    return 0;
}

