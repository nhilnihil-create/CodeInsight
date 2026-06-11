#include<iostream>
#include<vector>
#include<algorithm>
int main(){
	int max=0,count=0;
	std::vector<int> vec(100);
	std::vector<int> vec2(100);
	std::vector<int> vec3;
	while(1){
		for(int i=0;i<100;i++){
			std::cin>>vec[i];
			//if(vec[i]==0)break;
			vec2[vec[i]]++;
			if(vec2[vec[i]]>max)max=vec2[vec[i]];
			count++;
		}
		if(std::cin.eof())break;
	}
	for(int i=0;i<count;i++){
		if(vec2[vec[i]]==max){
			vec3.push_back(vec[i]);
			vec2[vec[i]]=0;
		}
	}
	sort(vec3.begin(),vec3.end());
	for(int i=0;i<vec3.size();i++)std::cout<<vec3[i]<<std::endl;
	return 0;
}