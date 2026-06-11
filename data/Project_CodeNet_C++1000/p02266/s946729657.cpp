#include<iostream>
#include<vector>
using namespace std;

const char kUp = '/';
const char kDown = '\\';
const char kFlat = '_';

int calc_area(const vector<int>& height, const int first, const int last){
	int h = height[first];
	int ret = 0;
	for(int i = first + 1; i <= last; i++){
	    ret += h - height[i];
	}
	return ret;
}

int SumVec(const vector<int> &vec) {
	int sum = 0;
	for(auto num : vec){
        sum += num;
	}
	return sum;
}

vector<int> FindLakeAndCalcArea(const vector<int> &height) {
    vector<int> lake_area;
	for(int i = 0; i < (int)height.size() - 1; i++){
        if(height[i] <= height[i+1]) { // 隣と高さが一緒か、右隣のほうが高い時
            continue;
        }
        for(int j = i+1; j <= (int)height.size() - 1; ++j){
			if(height[i] == height[j]){ // 湖を発見
				lake_area.push_back(calc_area(height, i, j));
				i = j - 1;
				break;
			}
        }
	}	
	return lake_area;
}

int main() {	
    vector<char> shape;
    char c;
	while(cin >> c){
        shape.push_back(c);
	}
    
    vector<int> height(shape.size()+1);  
    // height[0] = 0 を基準に高さを求める
	for(int i = 1; i <= (int)shape.size(); i++){
		switch(shape[i-1]){
		case kUp:
			height[i] = height[i - 1] + 1;
			break;
		case kDown:
			height[i] = height[i - 1] - 1;
			break;
		case kFlat:
			height[i] = height[i - 1];
			break;
		}
	}

	// 面積を求める
    vector<int> lake_area = FindLakeAndCalcArea(height);

	cout << SumVec(lake_area) << endl;

	cout << lake_area.size();
	for(auto x : lake_area){
        cout << " " << x;
	}
    cout << endl;
	
	return 0;
}
