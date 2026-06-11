#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long h, w, a, b;

  	cin >> h >> w >> a >> b;
  	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if((j<a&&i<b)||(a<=j&&b<=i&&j<w-1)){
				cout <<1;
			}else if((a<=j&&i<b&&j<w-1) || (j<a&&b<=i)){
				cout <<0;
			}else if((j==w-1)&&i<b){
				cout<<0<<endl;
			}else if((j==w-1)&&b<=i){
				cout<<1<<endl;
			}
		}
	}
}
