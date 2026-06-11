#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 

using namespace std; 

#define MP make_pair

long gcd(long a, long b){ 

  if(a%b==0) return b; 
  else return gcd(b,a%b); 

} 

long lcm(long a, long b){ 
  return a*b/gcd(a,b); 
} 

int main(){

	int h;
	while(cin>>h, h){

		vector< vector<int> > map(h , vector<int>(5));

		for(int i=0;i<h;i++){
			for(int j=0;j<5;j++){
				cin>>map[i][j];
			}
		}


		int res=0;
		while(true){

			bool flag=true;

			for(int i=0;i<h;i++){
				int num=map[i][0],len=1,pos=0;
				for(int j=1;j<5;j++){
					if(map[i][j]==num) len++;
					else if(len>=3) break;
					else{ num=map[i][j]; pos=j; len=1;}
				}

				if(len>=3 && num!=0){
					flag=false;
					res+=num*len;
					for(int j=0;j<len;j++) map[i][pos+j]=0;
				}

			}

			for(int i=h-2;i>=0;i--){
				for(int j=0;j<5;j++){
					int pos=i;
					while(pos+1<h && map[pos+1][j]==0) pos++;
					swap(map[i][j],map[pos][j]);
				}
			}


			if(flag) break;
		}

		cout<<res<<endl;

	}

	return 0;
}