#include<iostream>
#define C_MAX 10000
#define R_MAX 10

int h,w,ans;
int J[R_MAX][C_MAX];
bool flag[R_MAX] ;

int count(){
	int tmp,res=0;

	for(int j=0;j<w;++j){
		tmp=0;
		for(int i=0;i<h;++i){
			if(flag[i]&&!J[i][j] || !flag[i]&&J[i][j])
				++tmp;
		}
		if(tmp<h-tmp)
			res+=h-tmp;
		else res+=tmp;
	}
	return res;
}

int solve(int idx){
	int res;
	if(idx==h){
		res=count();
		if(ans<res)
			ans=res;
		return ans;
	}

	flag[idx]=false;
	solve(idx+1);

	flag[idx]=true;
	solve(idx+1);
}

int main(){
	while(1){
	  std::cin>>h>>w;
	  if(h==0&&w==0)
		  break;
	  for(int i=0;i<h;++i){
		  for(int j=0;j<w;++j){
			  std::cin>>J[i][j];
		  }
	  }
	  std::cout<<solve(0)<<std::endl;
	}
	return 0;
}