#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int> M;
int main(){
	int N=0,L=0;
	string word,fre,lon;
	while(cin>>word){
		M[word]+=1;
		if(M[word]>N){
			N=M[word];
			fre=word;
		}
		if(word.size()>L){
			L=word.size();
			lon=word;
		}
	}
	cout<<fre<<" "<<lon<<endl;
}