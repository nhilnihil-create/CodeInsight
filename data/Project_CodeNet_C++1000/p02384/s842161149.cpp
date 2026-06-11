#include <bits/stdc++.h>
using namespace std;
class dice{
public:
	int d1;
	int d2;
	int d3;
	int d4;
	int d5;
	int d6;
	int kaisi(int s1, int s2, int s3, int s4 ,int s5,int s6);
	string huru(string x);
	int kakunin(int x,int y);
};
int dice::kaisi(int s1,int s2,int s3,int s4,int s5,int s6){
  d1 = s1;
  d2 = s2;
  d3 = s3;
  d4 = s4;
  d5 = s5;
  d6 = s6;
}
/*string dice::huru(string x){
	int a,b,c,d,e,f;
	for(int i = 0;i<x.size();i++){
		if(x.at(i) == 'E'){
			a = d3;
			d3 = d1;
			d1 = d4;
			d4 = d6;
			d6 = a;
		}
		if(x.at(i) == 'S'){
			a = d2;
			d2 = d1;
			d1 = d5;
			d5 = d6; 
			d6 = a;
		}
		if(x.at(i) == 'W'){
			a = d4;
			d4 = d1;
			d1 = d3;
			d3 = d6;
			d6 = a;
		}
		if(x.at(i) == 'N'){
			a = d5;
			d5 = d1;
			b = d6;
			d6 = a;
			a = d2;
			d2 = b;
			d1  =  a;
		}
	}
} */
int dice::kakunin(int x,int y){
	int a1,a2,a3,a4,a5,a6;
	if(d1 == x){
        a1 = d1;
        a2 = d2;
        a3 = d3;
        a4 = d4;
        a5 = d5;
        a6 = d6;
        }
    else if(d2 == x){
		a1 = d2;
		a2 = d6;
		a6 = d5;
		a5 = d1;
		a4 = d4;
		a3 = d3;
		}
	else if(d3 == x){	
		a1 = d3;
		a2 = d2;
		a3 = d6;
		a4 = d1;
		a5 = d5;
		a6 = d4;
		}
	else if(d4 == x){	
		a1 = d4;
		a2 = d2;
		a3 = d1;
		a4 = d6;
		a5 = d5;
		a6 = d3;
		}
	else if(d5 == x){	
		a1 = d5;
		a2 = d1;
		a3 = d3;
		a4 = d4;
		a5 = d6;
		a6 = d2;
	}
	else if(d6 == x){	
		a1 = d6;
		a2 = d5;
		a3 = d3;
		a4 = d4;
		a5 = d2;
		a6 = d1;
	}

	if(y == a2)return a3;
	else if(y == a3)return a5;
	else if(y == a4)return a2;
	else if(y == a5)return a4;
	else return 0;
}
int main(){
	int s1,s2,s3,s4,s5,s6,huuta,x,y;
	cin>>s1>>s2>>s3>>s4>>s5>>s6;
	cin>>huuta;
	dice iti;
	iti.kaisi(s1,s2,s3,s4,s5,s6);
	for(int i = 0;i<huuta;i++){
		cin>>x>>y;
		cout<<iti.kakunin(x,y)<<endl;
	}
	return 0;
}
