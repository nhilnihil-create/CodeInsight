#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int l, r, d; cin>>l>>r>>d;
	cout<<((r / d) - (l / d - (l % d ? 0 : 1)));
}