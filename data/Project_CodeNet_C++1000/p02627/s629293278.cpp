#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define watch(x) cout << "["<<(#x) << " is " << (x) << "]" << endl
void watchVecI(vector<int>a){
	for(int i = 0; i < a.size(); ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}
void watchVecS(vector<string>a){
	for(int i = 0; i < a.size(); ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}
void watchVecC(vector<char>a){
	for(int i = 0; i < a.size(); ++i){
		cout << a[i];
	}
	cout << endl;
}
long double binets(double n){
	long double first = (1+sqrt(5.0))/2.0;
	long double second = (1-sqrt(5.0))/2.0;
	long double third = pow(first,n)-pow(second,n);
	return (third/sqrt(5.0));
}


void solve(){
  char a;
  cin >> a;
  if(a<=90){
    cout << 'A' << endl;
  }
  else{
    cout << 'a' << endl;
  }
}

int main(){
//	freopen("I_P.txt", "r", stdin);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
