#include<bits/stdc++.h>
#define lli long long int

using namespace std;
int main(){
	string a;
	cin>>a;
	char b = a.back();
	if(b =='2' || b == '4' || b == '5' || b == '7' || b=='9')
		cout<<"hon"<<endl;
	else if(b == '0' || b == '1' || b == '6' || b == '8')
		cout<<"pon"<<endl;
	else
	cout<<"bon"<<endl;
    return 0;
}
