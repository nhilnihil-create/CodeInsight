#include<iostream>

using namespace std;

int solve(int k);

int main(){

int n; cin >> n;


char *str = new char[n];
cin >> str;

int count = 0;
int i=0;
int j=n-1;

while(1){
	while(str[i]!='W'){

		i++;
		if(i==n)break;
	}

	while(str[j]!='R'){
		j--;
		if(j<0)break;
	}
	
	if(i>=j)break;
	i++;
	j--;
	count++;
}



printf("%d\n",count);

delete str;
	return 0;
}

