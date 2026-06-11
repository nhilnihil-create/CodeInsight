#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long int cnt;
vector<int> G;

void insertionSort(vector<int> &a,int n,int g){
	for (int i=g;i<n;i++){
    	int v=a.at(i);//gの間隔後から
    	int j=i-g;//最初はゼロから
      	while(j>=0 && a.at(j)>v){
        	a.at(j+g)=a.at(j);
          	j-=g;
          	cnt++;
        }
      a.at(j+g)=v;
    }
}

void shellSort(vector<int> &a,int n){
	//数列Gを生成
  	for(int h=1;;){
    	if(h>n)break;
      	G.push_back(h);
      	h=3*h+1;
    }
	for (int i=G.size()-1;i>=0;i--){
		insertionSort(a,n,G.at(i));
	}
  	
}

int main(){
	int n;cin>>n;
  	vector<int> a(n);
  
  	//数字を読み込み	
  	for(int i=0;i<n;i++){
    	scanf("%d",&a.at(i));
      	cnt=0;
    }
  	
  	shellSort(a,n);
  	cout<<G.size()<<endl;
  	for (int i=G.size()-1;i>=0;i--){
    	printf("%d",G.at(i));
        if(i) printf(" ");
    }
   	printf("\n");
   	printf("%d\n",cnt);
  	for (int i=0;i<n;i++) printf("%d\n",a.at(i));
  }
