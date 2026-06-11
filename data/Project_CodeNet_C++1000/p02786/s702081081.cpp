#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	ll h;
	cin >> h;
	ll i=1, count = 1;
	h = h/2;
	while(h!=0){
		h /= 2;
		//cout << h << " " << count << endl;
		//count += 2;
		//if(h==1) count += i;
		count += pow(2, i);
		//cout << h << " " << count << endl;
		i++;
	}
	cout << count << endl;
	return 0;
}
