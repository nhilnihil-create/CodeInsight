#include <iostream>
using namespace std;
int cnt1,cnt2;
int temp1[100],temp2[100];
string s;
int main(){
	while(1){
		getline(cin,s);
		if(s[0]=='.')break;
		cnt1=cnt2=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				cnt1++;
				temp1[cnt1]=cnt2;
			}else if(s[i]==')'){
				if(temp1[cnt1]!=cnt2)break;
				cnt1--;
			}else if(s[i]=='['){
				cnt2++;
				temp2[cnt2]=cnt1;
			}else if(s[i]==']'){
				if(temp2[cnt2]!=cnt1)break;
				cnt2--;
			}
			if(cnt1<0||cnt2<0)break;
		}
		if(cnt1==0&&cnt2==0){
			cout <<"yes" <<endl;
		}else{
			cout <<"no" <<endl;
		}
	}
}