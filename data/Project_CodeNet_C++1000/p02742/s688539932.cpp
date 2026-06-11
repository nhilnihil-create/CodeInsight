#include<iostream>
typedef long long ll;
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	ll h, r, t;
	cin >> h >> r;
	if(h==1 || r==1){
		t = 1;
		cout << t << endl;
		return 0;
	}
	t = (h*r+1)/2;
	//if(t%2==0) t = t/2;
	//else t = (t+1)/2;
	cout << t << endl;
	return 0;
}
