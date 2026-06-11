#include<iostream>
#include<string>
#include<vector>

using namespace std;

int m2i(string str){
	int sum=0,rank,Coefficient=1;
	for(int i=0;i<=str.size();i++){
		if(str[i]=='m'){
			rank = 1000;
			sum+=rank*Coefficient;
			Coefficient=1;
		}else if(str[i]=='c'){
			rank = 100;
			sum+=rank*Coefficient;			
			Coefficient=1;			
		}else if(str[i]=='x'){
			rank = 10;
			sum+=rank*Coefficient;			
			Coefficient=1;			
		}else if(str[i]=='i'){
			rank = 1;
			sum+=rank*Coefficient;			
			Coefficient=1;			
		}else {
			Coefficient = str[i]-0x30;
		}
	}
	return sum;
}

void print(int n){
	std::vector<int> v;
	string unit[4]={"m","c","x","i"};
	int num=n;
	int m=1000;
	while(m!=0){
		v.push_back(num/m);
		num = num%m;
		m/=10;
	}
	string str;
	int cnt=0;
	for(int i=0;i<v.size();i++){
		if(v[i]!=0 && v[i]!=1){
			cout << v[i] <<unit[cnt];
		}else if(v[i]==1){
			cout << unit[cnt];
		}
		cnt++;
	}
	cout << endl;
}

int main(){
	int n;
	// cout << m2i("x9i") << endl;

	cin >> n;
	while(n--){
		string str1,str2;
		cin >> str1 >> str2;
		print(m2i(str1)+m2i(str2));
	}
	return 0;
}