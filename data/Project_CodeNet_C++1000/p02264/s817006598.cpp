#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define max_datasets 500000

int main(){
	queue<string> data1;
	queue<int> data2;

	string kari_data1;
	int kari_data2;

	int all_time=0;

	int n,q;
	string name[max_datasets];
	int time[max_datasets];
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>name[i]>>time[i];
		data1.push(name[i]);
		data2.push(time[i]);
	}

	while(data1.size()!=0){
		if(data2.front()<=q){
			all_time += data2.front();
			cout<<data1.front()<<" "<<all_time<<endl;
			data1.pop();
			data2.pop();
		}
		else{
			data2.front() -= q;
			all_time += q;
			kari_data1=data1.front();
			kari_data2=data2.front();
			data1.pop();
			data2.pop();
			data1.push(kari_data1);
			data2.push(kari_data2);
		}
	}
	return 0;
}