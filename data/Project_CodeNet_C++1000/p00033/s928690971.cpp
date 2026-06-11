#include<iostream>
#include<vector>
using namespace std;
int main(){
	int time;
	cin>>time;
	int ball[10];
	vector<int> line1;
	vector<int> line2;
	for(int i2=0;i2<time;++i2){
		for(int i=0;i<10;++i){
			cin>>ball[i];
		}
		line1.push_back(ball[9]);
		for(int i=8;i>=0;--i){
			if(line1.back()>ball[i])line1.push_back(ball[i]);
			else if(line2.empty()||line2.back()>ball[i])line2.push_back(ball[i]);
			else {
				cout<<"NO"<<endl;
				goto NO;
			}
		}
		cout<<"YES"<<endl;
NO:;
		line1.clear();
		line2.clear();
	}
	return 0;
}