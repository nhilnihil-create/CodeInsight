#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

	int a,b;
	vector<int> sums;
	
	while(cin>>a>>b){
		
		sums.push_back(a+b);
	}
	
	int sum = a+b;
	int ten=1, shou;
	vector<int> keta;
	

	for(int i=0 ; i<sums.size() ; i++){
		keta.push_back(0);
		while(1){
			shou = sums[i]/ten;
			
			if(shou == 0){
				break;
			}
			
			keta[i]++;
			ten *= 10;
		}
		ten = 1;
	}

	for(int i ; i<sums.size() ; i++){
		cout<<keta[i]<<endl;
	}
	
return 0;
}