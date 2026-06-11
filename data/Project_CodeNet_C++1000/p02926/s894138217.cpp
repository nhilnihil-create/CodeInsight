#include<bits/stdc++.h>
using namespace std;

double angle(double a,double b){
	double p = a/(abs(a)+abs(b));
	if (b<0){
		return p-1;
	}else{
		return 1-p;
	}
}

bool com(pair<double,double> a,pair<double,double> b){
	return atan2(a.first,a.second) < atan2(b.first,b.second);
}

int main(){
	int n;cin>>n;
	vector<pair<double,double>> vecs(n);
	for(int i=0;i<n;++i){
		double a;double b;
		cin>>a>>b;
		vecs[i] = {a,b};
	}
	sort(vecs.begin(),vecs.end(),com);
    /*
	for(auto i:vecs){
		cout<<i.first<<" "<<i.second<<endl;
	}
    */
	double result = 0;
	for(int i=0;i<n;++i){
		pair<double,double> pr = {0.0, 0.0};
		for(int j=0;j<n;++j){
			pr.first += vecs[(i+j)%n].first;
			pr.second += vecs[(i+j)%n].second;
            result = max(result,sqrt(pr.first*pr.first + pr.second*pr.second));
		}
	}
	cout<<setprecision (30)<<result<<endl;
	return 0;
}