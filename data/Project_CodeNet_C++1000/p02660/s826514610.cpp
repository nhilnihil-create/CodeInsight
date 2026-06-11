#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>

#define rep(i,p) for(int i=0;i<p;i++)
#define ll long long

using namespace std;


//------------------素因数分解
vector<long long int> pri_fuc(long long int N){
	vector<long long int> p;
	for(long long int q=2;q*q<=N;q++){
		if(N%q == 0){
			while(N%q==0){
				p.push_back(q);
				N /= q;
			}
		}
	}
	if(N != 1){
		p.push_back(N);
	}
	return p;
}

int main(){

 ll int N;
 cin >> N;

 vector<ll int> A;

 A = pri_fuc(N);

 ll int a;
 a = A.size();

 ll int b=1;
 ll int counter=0;
 ll int counter2=0;
 ll int check=1;


 for(ll int i=0;i<a;i++){
if(i==11){
}
  if(A[i]!=b){
	  counter +=1;
	  b = A[i];
	  check = 1;
	  counter2 = 0;
  }
  else{
	  counter2 += 1;
	  if(check + 1==counter2){
		  counter+=1;
		  check += 1;
		  counter2 = 0;
	  }
	  else{}
  }

 }

 cout << counter;












	return 0;

}

