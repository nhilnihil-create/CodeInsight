#include <bits/stdc++.h>
#define ll long long int
#define booga cout << "booga" << endl
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void testcase(){

}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	cin >> a >> b;
	if((a+b)&1){
		cout << "IMPOSSIBLE \n";
	}
	else{
		cout << (a+b)/2 << "\n";
	}
	return 0;
}

