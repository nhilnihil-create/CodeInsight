#include <iostream>
#include <vector>

unsigned long long merge(	std::vector<int>::iterator left,
			std::vector<int>::iterator mid, 
			std::vector<int>::iterator right){

	unsigned long long cnt = 0;
	std::vector<int> L(mid-left),R(right-mid);

	for(std::vector<int>::iterator i=left; i!=mid; i++) L[i-left] = *i;
	L.push_back(1000000000);
	for(std::vector<int>::iterator i=mid; i!=right; i++) R[i-mid] = *i;
	R.push_back(1000000000);

	int ri = 0, li = 0;
	for(int k=0; k<right-left; k++){
		if(L[li]>R[ri]){
			*(left+k) = R[ri];
			if( (mid+ri)>(left+k) ) cnt += (mid+ri)-(left+k);
			ri += 1;
		}else{
			*(left+k) = L[li];
			li += 1;
		}
	}
	return cnt;
}

unsigned long long mergeSort(	std::vector<int>::iterator left, 
				std::vector<int>::iterator right ){
	unsigned long long cnt = 0;
	if(right-left>1){	
		int num = right - left;
		std::vector<int>::iterator mid = left + num/2;
		cnt += mergeSort(left,mid);
		cnt += mergeSort(mid,right);
		cnt += merge(left,mid,right);
	}
	return cnt;
}

int main(int argc, char const *argv[]){
	int n;
	unsigned long long cnt;
	std::cin >> n;
	std::vector<int> S(n);
	// for(int i=0; i<n; i++) S[i] = n-i;
	for(int i=0; i<n; i++) std::cin >> S[i];
	cnt = mergeSort(S.begin(),S.end());
	// for(int i=0; i<n; i++) std::cout << S[i] << ((i<n-1)?" ":"\n");
	std::cout << cnt << std::endl;
	return 0;
}
