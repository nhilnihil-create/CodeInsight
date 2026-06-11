#include<bits/stdc++.h>

using namespace std;

int main(){

  int m,n_min,n_max;

  while(1){

	cin>>m>>n_min>>n_max;

	if(m==0 && n_min==0 && n_max==0)
	  break;

	vector<int> score(m+1);
	int d=0;
	int num;

	for(int i=1;i<=m;++i)
	  cin>>score[i];

	for(int i=n_min;i<=n_max;++i){
	  if(score[i]-score[i+1] >= d){
		d = score[i]-score[i+1];
		num=i;
	  }
	}
	cout<<num<<endl;
  }
  
}

