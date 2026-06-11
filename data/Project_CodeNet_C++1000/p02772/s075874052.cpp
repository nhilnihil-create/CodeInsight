#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll; 


int main(){
	int n;
	cin >> n;
	int a;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a%2==0){
			if(a%3!=0 && a%5!=0){
				cout << "DENIED" << endl;
				return 0;
			}
		}
	} 

	cout << "APPROVED" << endl;
	return 0;
}
