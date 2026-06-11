#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int i=0,n=0,s=0,cnt=0,ans=0;
int combination(int a,int b,int c);


int combination(int a,int b,int c) 
//0-9テ」ツ?ョテヲツ閉ーテ・ツュツ療」ツつ誕,テ」ツ?敕」ツつ古」ツ?ァティツィツ暗ァツョツ療」ツ?療」ツ?淌ヲツ閉ーテ・ツ?、テ」ツつ鍛,テヲツ。ツ?ヲツ閉ーテ」ツつ団テ」ツ?ィテ」ツ?凖」ツつ?
{
	if(b == s && c == n){	//ティツィツ暗ァツョツ療」ツ?療」ツ?淌ヲツ閉ーテ・ツ?、テ」ツ?凝」ツ?、テ・ツ青暗ィツィツ?テ」ツ?ィテヲツ。ツ?ヲツ閉ーテ」ツ?古・ツ?・テ・ツ環崚」ツ?ィテ、ツクツ?ィツ?エテ」ツ?療」ツ?淌・ツ?エテ・ツ青?
		ans++;				//1テゥツ?堙」ツつ甘ィツヲツ凝」ツ?、テ」ツ?凝」ツ?」テ」ツ?淌」ツ?ョテ」ツ?ァテッツシツ妥ゥツ?堙」ツつ甘」ツδ療」ツδゥテ」ツつケテ」ツ?凖」ツつ?
	}
	if(a == 10 || c == n){	//0-9テ」ツ?ョテヲツ閉ーテ・ツ?、テ」ツつ津ヲツ篠「テ」ツ?療ァツオツづ」ツつ湘」ツ?」テ」ツ?淌」ツ?凝」ツ??ヲツ。ツ?ヲツ閉ーテ」ツ?古・ツ?・テ・ツ環崚」ツ?ィテ、ツクツ?ィツ?エテ」ツ?療」ツ?淌・ツ?エテ・ツ青?
		return 0;
	}
	combination(a+1,b,c);	//テヲツ閉ーテ・ツ?、テ」ツつ?1テ」ツ?療」ツ?ヲテ・ツ?催ィツ?ε」ツ?凖」ツつ?
	combination(a+1,b+a,c+1);	//テヲツ閉ーテ・ツ?、テ」ツつ?1テ」ツ?療」ツ??・ツ青暗ィツィツ暗」ツ?ォテヲツ閉ーテ・ツ?、テ」ツつ津ィツカツウテ」ツ?療」ツ??ヲツ。ツ?ヲツ閉ーテ」ツつ津・ツ「ツ療」ツつ?」ツ?療」ツ?ヲテ・ツ?催ィツ??
}
int main()
{
	while(cin >> n >> s && n && s>=0){
		ans=0;
		combination(0,0,0);
		cout << ans << endl;
	}
}