#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int y,m,d;
		cin>>y>>m>>d;

		int cnt=0;

		while(1){
			d++;
			cnt++;

			if(y%3==0){
				if(d==21){
					d=1;
					m++;
				}
			}
			else{
				if(m%2==0){
					if(d==20){
						d=1;
						m++;
					}
				}
				else{
					if(d==21){
						d=1;
						m++;
					}
				}
			}

			if(m==11){
				y++;
				m=1;
			}
			//cout<<"y="<<y<<" m="<<m<<" d="<<d<<endl;
			if(y==1000&&m==1&&d==1)break;
		}
		cout<<cnt<<endl;
	}
	return 0;
}