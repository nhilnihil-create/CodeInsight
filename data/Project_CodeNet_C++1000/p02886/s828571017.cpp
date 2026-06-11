#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
int b[n];
for(int i=0;i<n;i++){
    cin>>b[i];
}
int sum=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        sum+=b[i]*b[j];}}
        cout<<sum;
	return 0;
}