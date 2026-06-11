#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

void Print(int wide, int height);

void Print(int wide, int height)
{
	for(int h = 0; h < height; h++){
		for(int w = 0; w < wide; w++){
			if(h != 0 && h != height - 1 
			&& w != 0 && w != wide - 1){
				cout << ".";
			} else{
				cout << "#";
			}
		}
		cout << endl;
	}
}

int main(){
	int w, h;
	vector<int> wide;
	vector<int> height;
	
	wide.clear();
	height.clear();
	while(1){
		cin >> h;
		cin >> w;
		if(h == 0 && w == 0)	break;
		height.push_back(h);
		wide.push_back(w);
	}
	
	for(int i = 0; i < height.size(); i++){
		Print(wide[i], height[i]);
		cout << endl;
	}
	
}