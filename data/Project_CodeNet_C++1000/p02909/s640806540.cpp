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


string S,A;
cin >> S;

if( S[0] == 'S'){
	cout << "Cloudy";
}
else if(S[0] == 'C'){
	cout << "Rainy";
}
else{
	cout << "Sunny";
}






	return 0;

}

