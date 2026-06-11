#include <iostream>

using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	
	int t_attack = (int)((double)c / (double)b + 0.9);
	int a_attack = (int)((double)a / (double)d + 0.9);
	
	if(t_attack > a_attack) cout << "No";
	else cout << "Yes";
	cout << endl;
	
	return 0;
	
}