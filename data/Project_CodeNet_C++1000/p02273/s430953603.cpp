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

void solve(list<Ten>::iterator P1, list<Ten>::iterator P2, list <Ten> &list1 ,int n){
	if(n ==0){
		return;
	}
	Ten s;
	Ten u;
	Ten t;
	Ten v;
	
	v.X=(P2->X-P1->X)/3;
	v.Y=(P2->Y-P1->Y)/3;
	s.X =P1->X+v.X;
	s.Y =P1->Y+v.Y;
	u.X=s.X+(v.X*cos(60*M_PI/180)-v.Y*sin(60*M_PI/180));
	u.Y=s.Y+(v.X*sin(60*M_PI/180)+v.Y*cos(60*M_PI/180));
	t.X =P2->X-v.X;
	t.Y =P2->Y-v.Y;

	list<Ten>::iterator itr_t = list1.insert(P2, t);
	list<Ten>::iterator itr_u = list1.insert(itr_t, u);
	list<Ten>::iterator itr_s = list1.insert(itr_u,s);

	n--;
	
	
		
		solve(P1, itr_s, list1, n);
		solve(itr_s, itr_u, list1, n);
		solve(itr_u, itr_t, list1, n);
		solve(itr_t, P2, list1, n);
	
	
}



int main(void){
	int n;
	
	cin >> n;
	list <Ten> list1;

	Ten siten;
	siten.X =0;
	siten.Y =0;
	Ten syuten;
	syuten.X =100;
	syuten.Y =0;
	
	list1.push_back(siten);
	list1.push_back(syuten);
	
	solve(list1.begin() , --list1.end(), list1,n);
	
	
	
	for(list<Ten>::iterator i=list1.begin() ; i != list1.end(); i++){
		
		cout << (*i).X << " "<< (*i).Y  <<endl;
		
		
	}
	
return 0;
	
}