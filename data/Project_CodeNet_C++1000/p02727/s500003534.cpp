#include<iostream>
#include<algorithm>
#include<vector>

int main(){
	int x, y, a, b, c;
	std::cin>> x>> y>> a>> b>> c;

	std::vector<long long> aList(a);
	std::vector<long long> bList(b);
	std::vector<long long> cList(c);

	std::vector<long long> xList;

	for(int i=0; i<a; i++)
		std::cin>>aList[i];

	for(int i=0; i<b; i++)
		std::cin>>bList[i];

	for(int i=0; i<c; i++)
		std::cin>>cList[i];

	std::sort(aList.begin(), aList.end(), [](long long s, long long t){return s > t;});
	std::sort(bList.begin(), bList.end(), [](long long s, long long t){return s > t;});
	std::sort(cList.begin(), cList.end(), [](long long s, long long t){return s > t;});

	int cIdx= 0;

	if(x<=a){
		for(int i=0; i< x; i++)
			xList.push_back(aList[i]);
	}else{
		for(int i=0; i< a; i++)
			xList.push_back(aList[i]);

		for(int i=0; i< x-a; i++, cIdx++){
			xList.push_back(cList[cIdx]);
		}
	}

	if(y<=b){
		for(int i=0; i< y; i++)
			xList.push_back(bList[i]);
	}else{
		for(int i=0; i< b; i++)
			xList.push_back(bList[i]);

		for(int i=0; i< y-b; i++, cIdx++){
			xList.push_back(cList[cIdx]);
		}
	}

	std::sort(xList.begin(), xList.end(), [](long long s, long long t){return s < t;});

	for(int i=0; cIdx< c && i< x+y; i++, cIdx++){
		if(xList[i]< cList[cIdx])
			xList[i]= cList[cIdx];
	}

	long long ans=0;
	for(int i=0; i< x+y; i++)
		ans+= xList[i];

	std::cout<<ans<<std::endl;

}