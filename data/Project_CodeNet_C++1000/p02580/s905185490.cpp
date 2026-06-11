#include<iostream>
#include<vector>

int main(){
	int h,w,m;
	std::cin>>h>>w>>m;

	std::vector<int> yList(m);
	std::vector<int> xList(m);

	for(int i=0; i< m; i++)
		std::cin>>yList[i]>>xList[i];

	std::vector<long long> yCount(h, 0);
	std::vector<long long> xCount(w, 0);

	for(int i=0; i<m; i++){
		yCount[yList[i]-1]++;
		xCount[xList[i]-1]++;
	}

	long long maxX=0;
	long long maxY=0;
	for(int i=0; i<w; i++)
		if(maxX< xCount[i])
			maxX= xCount[i];

	for(int i=0; i<h; i++)
		if(maxY< yCount[i])
			maxY= yCount[i];

	std::vector<int> maxXIdx;
	std::vector<int> maxYIdx;

	for(int i=0; i< w; i++)
		if(xCount[i] == maxX)
			maxXIdx.push_back(i);

	for(int i=0; i< h; i++)
		if(yCount[i] == maxY)
			maxYIdx.push_back(i);

	long long duplicateCount= 0;
	long long duplicateMax= maxXIdx.size() * maxYIdx.size();

	for(int i=0; i<m; i++){
		bool isExistX= false;
		bool isExistY= false;

		auto itrX = std::lower_bound(maxXIdx.begin(), maxXIdx.end(), xList[i]-1);
		isExistX= (itrX!= maxXIdx.end() && *itrX == xList[i]-1);

		auto itrY = std::lower_bound(maxYIdx.begin(), maxYIdx.end(), yList[i]-1);
		isExistY= (itrY!= maxYIdx.end() && *itrY == yList[i]-1);

		if(isExistX && isExistY)
			duplicateCount++;
	}

	long long ans = maxX + maxY + ((duplicateCount< duplicateMax)? 0 : -1);

	std::cout<<ans<<std::endl;

	return 0;
}