#include<bits/stdc++.h>
using namespace std;

#define ASC(vec) vec.begin(), vec.end() 
#define DESC(vec) vec.rbegin(), vec.rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define In(vec) rep(i, n) cin>>vec[i]; 
#define ANS(s) cout << s << endl;
#define inc(a, b) cin >> a >> b;

int main(){
	string tamesi;
	int tamesi2 = 0;
	cin>>tamesi;
	for (int i = 0; i < tamesi.size(); i++) {
		if((i%2)==0){
				if((tamesi[i]=='R')||tamesi[i]=='U'||tamesi[i]=='D'){
						tamesi2 += 1;
				}
		}
		else{
				if(tamesi[i]=='L'||tamesi[i]=='U'||tamesi[i]=='D'){
						tamesi2 += 1;
				}
		}
	}
	if (tamesi2==tamesi.size()) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	return 0;
}
