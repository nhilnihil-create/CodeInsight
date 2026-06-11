#include <iostream>
#include <list> //???????????????????????????
#include <vector>//????????¢??????????????????
#include <climits>
#include <cmath>
using namespace std;

struct Ten{
	double X;
	double Y;

};

void out(Ten t){
	
	cout << t.X << " "<<t.Y <<endl;
	
}

void solve(Ten P1, Ten P2 ,int n){
	if(n ==0){
		return;
	}
	Ten s;
	Ten u;
	Ten t;
	Ten v;
	
	v.X=(P2.X-P1.X)/3;
	v.Y=(P2.Y-P1.Y)/3;
	s.X =P1.X+v.X;
	s.Y =P1.Y+v.Y;
	u.X=s.X+(v.X*cos(60*M_PI/180)-v.Y*sin(60*M_PI/180));
	u.Y=s.Y+(v.X*sin(60*M_PI/180)+v.Y*cos(60*M_PI/180));
	t.X =P2.X-v.X;
	t.Y =P2.Y-v.Y;

	/*Ten itr_t = list1.insert(P2, t);
	Ten itr_u = list1.insert(itr_t, u);
	Ten itr_s = list1.insert(itr_u,s);*/

	
	if(n == 1){
		//out(P1);
		//out(s);
		//out(u);
		//out(t);
		//out(P2);
		
	}
	n--;
	
	solve(P1, s , n);
	if(n==0){
		out(s);
	}
	solve(s, u, n);
	if(n==0){
		out(u);
	}
	solve(u, t, n);
	if(n==0){
		out(t);
	}
	solve(t, P2, n);
	
	if(n ==0){
		out(P2);
	}
}



int main(void){
	int n;
	
	cin >> n;
	
	
	//list <Ten> list1;

	Ten siten;
	siten.X =0;
	siten.Y =0;
	Ten syuten;
	syuten.X =100;
	syuten.Y =0;
	
	/*list1.push_back(siten);
	list1.push_back(syuten);*/
	out(siten);
	solve(siten, syuten, n);
	//out(syuten);
	
	
	/*for(Ten i=list1.begin() ; i != list1.end(); i++){
		
		cout << (*i).X << " "<< (*i).Y  <<endl;
		
		
	}*/
	if(n ==0){
		out(syuten);
	}
return 0;
	
}