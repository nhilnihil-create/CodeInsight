#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main() {
	stack<int> order;
	stack< pair<int,int> > area;//first...area second...x1
	
	int tmpOrder=1;
	int totalArea=0;
	int tmpArea=0;
	char c;
	while(cin>>c){
		int x1=0;
		int x2=0;
		
		switch(c){
			case '/':
				if(order.empty()){
					continue;
				}
				x1=order.top();order.pop();
				x2=tmpOrder;
				tmpArea=x2-x1;
					while(!area.empty()){
						if(area.top().second>x1){
							tmpArea += area.top().first;
							area.pop();
						}else{
							break;
						}
					}
				area.push(make_pair(tmpArea,x1));
				break;
			case '_':
				break;
			default:
				order.push(tmpOrder);
				break;
		}
		tmpOrder++;
	}
	
	int size1= area.size();
	int size2= area.size();
	stack<int> ans;
	
	while(size1--){
		totalArea += area.top().first;
		ans.push(area.top().first);
		area.pop();
	}
	cout<<totalArea<<endl;
	cout<<size2;
	size2 = ans.size();
	
	while(size2--){
		cout<<" "<<ans.top();
		ans.pop();
	}
	cout<<endl;
	
	return 0;
}