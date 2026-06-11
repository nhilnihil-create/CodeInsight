#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	for(;;){
	int n,temp;
	double m=0;
	double alphasqured=0;
	vector<int> s;
	cin >> n;			//母体数の取得
	if(n==0)break;
	s.clear();
	s.reserve(n);		//確保
	for(int i=0;i<n;i++){
		cin >> temp;	//各得点の読み込み
		s.push_back(temp);//コンテナへの書き込み
		m+=(double)temp/n;//平均への追加
	}
	for(int i=0;i<n;i++){	alphasqured+=pow((s.at(i)-m),2)/n;}
	printf("%.4f\n",sqrt(alphasqured));
	}
	return 0;
}