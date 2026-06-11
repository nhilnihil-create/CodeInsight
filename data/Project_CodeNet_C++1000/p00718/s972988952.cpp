#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
string lower_case = "abcdefghijklmnopqrstuvwxyz";
int judge(char s){
	if(s=='m')return 1000;
	else if(s=='c')return 100;
	else if(s=='x')return 10;
	else if(s=='i')return 1;
}
int decode(string s){
	int i,sum=0;
	for(i=0;i<s.size()||!s.empty();){
//		cout<<"s:"<<s<<endl;
		int d=1;
		int num=1;
//		cout<<"___"<<s<<endl;
		i=s.find_first_of(lower_case);
//		cout<<"i:"<<i<<endl;
		int index=i;
		if(i>0&&(s[i-1]>='0'&&s[i-1]<='9')){
			index--;d++;
			num=s[i-1]-'0';
		}
		sum+=num*judge(s[i]);
//		cout<<"("<<s[i]<<")sum:"<<sum<<endl;
//		cout<<"erase:"<<index<<"_"<<d<<endl;
		s.erase(index,d);

	}
	return sum;
}
string convert(int n){
	int d=1000;
	string s="";
//	cout<<"convert"<<endl;
	for(;d>0;d/=10){
		if((n/d)%10){
			if((n/d)%10>1)s+='0'+(n/d)%10;
			if(d==1000)s+="m";
			else if(d==100)s+="c";
			else if(d==10)s+="x";
			else if(d==1)s+="i";
		}
//		cout<<"d:"<<d<<" s:"<<s<<endl;
	}
	return s;
}
int main(){
	int sum,d;
	cin>>d;
	string str1,str2;
	for(;d>0;d--){
		cin>>str1>>str2;
		sum=decode(str1)+decode(str2);
//		cout<<"sum_"<<sum<<endl;
//		cout<<"-----------"<<endl;
		cout<<convert(sum)<<endl;;
	}
	return 0;
}