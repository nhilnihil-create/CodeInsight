#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int sheep,wolf;
	cin>>sheep>>wolf;
	if(wolf>=sheep)cout<<"unsafe";
	else cout<<"safe";
	return 0;
}
