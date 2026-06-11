#include <bits/stdc++.h>
using namespace std;

int a,b;
int main() {
cin>>a>>b;
if(a<10){
	cout<<b+(100*(10-a));
}else{
	cout<<b;
}
}