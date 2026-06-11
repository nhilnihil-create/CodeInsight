#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		if(s==".") break;
		int a[200][200],k1=0,k2=0,b=0,c1=0,c2=0,c3=0,c4=0;
		for(int i=0;i<200;i++){
			for(int j=0;j<200;j++){
				a[i][j]=0;
			}
		}
		a[100][100]=1;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='('){
				k1++;
				a[100+k1][100+k2]++;
				c1++;
			}
			else if(s[i]==')'){
				a[100+k1][100+k2]=0;
				k1--;
				if(a[100+k1][100+k2]==0){
					b++;
				}
				c2++;
			}
			else if(s[i]=='['){
				k2++;
				a[100+k1][100+k2]++;
				c3++;
			}
			else if(s[i]==']'){
				a[100+k1][100+k2]=0;
				k2--;
				if(a[100+k1][100+k2]==0){
					b++;
				}
				c4++;
			}
		}
		if(b==0&&c1==c2&&c3==c4){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
		string s(200,'a');
	}
    return 0;
}