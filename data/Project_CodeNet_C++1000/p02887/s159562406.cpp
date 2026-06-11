#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
string b;
cin>>b;
int c=1;
for(int i=1;i<n;i++){
    if(b[i-1]!=b[i]){
        c++;
    }
}
cout<<c;
	return 0;
}