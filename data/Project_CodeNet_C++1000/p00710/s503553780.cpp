#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int array[51];
int main(){
  int M,N;
  vector<int> v;
  while(cin>>M >>N){
    if(N==0&&M==0){
      break;
    }
    for(int k=0;k<M;k++){//初期化
      array[k]=k+1;
    }
    int p=0,c=0;
    for(int i=0;i<N;i++){
      cin >>p >>c;

      for(int a=0;a<p-1;a++){//上保存
	v.push_back(array[(M-1)-a]);
      }

      for(int t=0;t<c;t++){//下を上へ
	array[(M-1)-t]=array[(M-1)-(p-1)-t];

      }

      for(int l=0;l<p-1;l++){//上を下へ
	array[(M-1)-c-l]=v.front();
	v.erase(v.begin());

      }

      /*
      for(int g=M-1;g>=0;g--){//配列確認
	cout << array[g] <<endl;
	}*/



    }
      cout << array[M-1] <<endl; 
  }
  
  return 0;
}