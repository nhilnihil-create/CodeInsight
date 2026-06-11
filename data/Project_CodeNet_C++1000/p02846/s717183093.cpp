#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	if(A1*T1+A2*T2==B1*T1+B2*T2){
		cout << "infinity" << endl;
		return 0;
	}
	if(A1*T1+A2*T2>B1*T1+B2*T2){
		swap(A1, B1);
		swap(A2, B2);
	}
	if(A1<B1){
		cout << 0 << endl;
		return 0;
	}
	ll d=(B1*T1+B2*T2)-(A1*T1+A2*T2);
	ll f=((A1-B1)*T1+d-1)/d;
	if(((A1-B1)*T1)%d==0) cout << f*2 << endl;
	else cout << f*2-1 << endl;
	return 0;
}