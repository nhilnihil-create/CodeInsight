#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>

#define rep(i,p) for(long long int i=0;i<p;i++)
#define reep(i,p) for(long long int i=1;i<=p;i++)
#define ll long long

using namespace std;

int main(){

ll int N;
cin >> N;
if(N%2 ==0){
	cout << fixed << setprecision(6) << 1.0/2.0;
}

else{
	cout << fixed << setprecision(6) <<( (double)(N-1)/2.0+1)/(double)(N);
}









	return 0;

}

