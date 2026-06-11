#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX_N 150

struct rect{
	int h, w;
};

vector<rect> Rect;

bool operator<(const rect r1, const rect r2){
	double diagonal1 = (double)r1.h*(double)r1.h + (double)r1.w*(double)r1.w;
	double diagonal2 = (double)r2.h*(double)r2.h + (double)r2.w*(double)r2.w;
	return (diagonal1 == diagonal2) ? (r1.h < r2.h) : (diagonal1 < diagonal2);
}

void calcRect(){
	for(int i = 1; i <= MAX_N; i++){
		for(int j = i+1; j <= MAX_N; j++){
			rect r;
			r.h = i;
			r.w = j;
			Rect.push_back(r);
		}
	}
}

int main(){
	int h, w;
	calcRect();
	sort(Rect.begin(), Rect.end());
	while( cin >> h >> w, h || w ){
		for(int i = 0; i < Rect.size(); i++){
			if( Rect[i].h == h && Rect[i].w == w ){
				cout << Rect[i+1].h << " " << Rect[i+1].w << endl;
				break;
			}
		}
	}
}