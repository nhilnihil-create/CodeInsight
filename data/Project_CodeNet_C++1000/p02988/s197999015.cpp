#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int vec[21];
int cont=0;
for(int i=0;i<n;i++){
	cin>>vec[i];
}
for(int i=0;i<n;i++){
	if(i!=0&&i!=n-1){
		if(vec[i]>vec[i-1]&&vec[i]<vec[i+1]||vec[i]<vec[i-1]&&vec[i]>vec[i+1])
		cont++;
	}
}
cout<<cont<<"\n";
    return(0);
}