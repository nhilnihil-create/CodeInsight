#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	char b[101];
	while(true){
	int count=0;
	getline(cin,a);
	if(a==".")
		break;
	for(int i=0;i<a.size();i++){
		if(a[i]=='('||a[i]==')'||a[i]=='['||a[i]==']'){
			b[count]=a[i];
			count++;
		}
	}
	int check;
	while(true){
		check=count;
		for(int i=0;i<count-1;i++){
			if((b[i]=='('&&b[i+1]==')')||(b[i]=='['&&b[i+1]==']')){
				for(int j=0;j<count;j++){
					if(j<i)
						b[j]=b[j];
					if(j>i+1)
						b[j-2]=b[j];
				}
				count-=2;
			}
		}
		if(count==check)
			break;
	}
	if(count==0)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	}
    return 0;
}