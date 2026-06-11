#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
	cout << max((c*60+d)-(a*60+b)-e,0);
}
