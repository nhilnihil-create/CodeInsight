#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
long int a=0;
cin >> N;
for(int i=1;i<N+1;i++){
	if(i%3!=0&&i%5!=0) a += i;
}
cout << a << endl;
}