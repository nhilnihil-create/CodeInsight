#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

double n;
cin>>n;

double l=n/1.08;
double r=(n+1)/1.08;

if(ceil(l)==l){
	cout<<l;
}
else if(r>ceil(l)){
	cout<<ceil(l);
}
else
	cout<<":(";



}
