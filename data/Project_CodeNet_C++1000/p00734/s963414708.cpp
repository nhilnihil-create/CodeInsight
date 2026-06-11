#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<string> ans;
int n,m;
string tostr(int num);

int main(){
	while(1){
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		int nh[100],mh[100];
		int cn = -1,cm = -1;
		int sumn = 0,summ = 0;
		int sumc = 1000;
		for(int i = 0;i < n;i++){
			cin >> nh[i];
			sumn+=nh[i];
		}
		for(int i = 0;i < m;i++){
			cin >> mh[i];
			summ+=mh[i];
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if((sumn - nh[i] + mh[j]) == (summ - mh[j] + nh[i]) && sumc > nh[i] + mh[j]){
					sumc = nh[i] + mh[j];
					cn = nh[i];
					cm = mh[j];
				}
			}
		}
		if(cn != -1){
			string ts;
			ts += tostr(cn);
			ts += ' ';
			ts += tostr(cm);
			ans.push_back(ts);
		}
		else{
			string ts;
			ts += "-1";
			ans.push_back(ts);
		}
	}
	for(int i = 0;i < ans.size();i++){
		cout << ans[i] << endl;
	}
}

string tostr(int num){
	string str;
	for(int i = num;i > 0;i=i/10){
		str += '0' + (i%10);
	}
	reverse(str.begin(),str.end());
	return str;
}