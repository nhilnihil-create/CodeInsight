#include<string>
#include<stdio.h>
using namespace std;

string ctable[] = {
	".,!? ",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

int main(){
	int cases;
	cin>>cases;
	while(cases--){
		string str;
		cin>>str;
		
		int mem = 0;//times * 10 + type
		for(int i = 0; i < str.size(); i++){
			int t = (int)(str[i]-'0');
			if(!t){
				if(mem){
					cout<<ctable[mem%10-1].at((mem/10)%ctable[mem%10-1].size());
				}
				mem = 0;
			}else{
				if(mem%10 == t)mem+=10;
				else mem = t;
			}
		}
		cout<<endl;
	}
	return 0;
}