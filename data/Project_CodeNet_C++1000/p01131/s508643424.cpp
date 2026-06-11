#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main(){

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string str;
		char last;
		char key[10][13]={
			{' '},
			{' ','.',',','!','?',' '},
			{' ','a','b','c','a','b','c','a','b','c','a','b','c'},
			{' ','d','e','f','d','e','f','d','e','f','d','e','f'},
			{' ','g','h','i','g','h','i','g','h','i','g','h','i'},
			{' ','j','k','l','j','k','l','j','k','l','j','k','l'},				
			{' ','m','n','o','m','n','o','m','n','o','m','n','o'},
			{' ','p','q','r','s','p','q','r','s','p','q','r','s'},
			{' ','t','u','v','t','u','v','t','u','v','t','u','v'},
			{' ','w','x','y','z','w','x','y','z','w','x','y','z'},								
		};
		cin >> str;
		int array[10],i;
		for(i=0;i<10;i++){
			array[i]=0;
		}
		last = str[0];
		for(i=0;i<str.size();i++){
			array[str[i]-0x30]++;
			if(array[str[i]-0x30] > 12 && last!=1) array[str[i]-0x30]=1;
			if(array[1] > 5) array[1]=1;
			if(str[i]=='0' && last!='0'){
				// cout << last << ':' << array[last-0x30] << endl;
				cout <<  key[(last-0x30)][array[last-0x30]];
				for(int l=0;l<10;l++){
					array[l]=0;
				}
			}
			last = str[i];
		}
		cout << endl;
	}
	return 0;
}