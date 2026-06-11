#include <bits/stdc++.h>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define rep(i,a,b) for(int (i)=int(a);(i)<int(b);(i)++)
#define rrep(i,a,b) for(int (i)=int(a);(i)>=int(b);(i)--)

#define put(a) cout << (a) << endl
#define puts(a) cout << (a) << " "

#define llint long long int

int main (void)
{
	//INPUT
	llint T1,T2,A1,A2,B1,B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	
	//SOLVE
	llint x1,x2;
	
	if (A1 < B1 ) {
		if (A2 < B2) {
			put("0");
			return 0;
		}
		
		//A1 < B1   A2 > B2
		x1 = B1 - A1;	//+
		x2 = B2 - A2;	//-
		
		
		
	} else {
		if (A2 > B2) {
			put("0");
			return 0;
		}
		
		//A1 > B1   A2 < B2
		x1 = A1 - B1;	//+
		x2 = A2 - B2;	//-
		
	}
	
	//SOLVE
	llint P = x1*T1;
	llint Q = x2*T2;
	llint PpQ = P+Q;
	
	// put(P);
	// put(Q);
	
	if (PpQ == 0) {
		put("infinity");
		return 0;
	} else if (PpQ > 0) {
		put("0");
		return 0;
	} else {
		//PpQ < 0
		llint N = (-P / PpQ);
		if ( -P % PpQ == 0) {
			put(2*N);
			return 0;
		} else {
			put(2*N+1);
			return 0;
		}
	}
	
	return 0;
}

