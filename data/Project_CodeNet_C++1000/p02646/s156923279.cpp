#include <iostream>
using namespace std;
typedef long long LL;
int main(int argc, char* argv[])
{
	LL A,V,B,W,T;
	cin>>A>>V;
	cin>>B>>W;
	cin>>T;
	if (A==B){
		cout<<"YES"<<endl;
		return 0;
	}
	if (V<=W){
		cout<<"NO"<<endl;
		return 0;
	}
	LL AB=A-B;
	if (AB<0){
		AB=-AB;
	}
	if (T*(V-W)>=AB){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}
