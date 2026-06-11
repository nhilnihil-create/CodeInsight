#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Heap{
public:
	Heap(){
		array = new long long[2000000];
		n = 0;
	}
	void insert(long long data){
		array[n] = data;
		int tmp = n;
		while(tmp != 0 && array[tmp] > array[(tmp-1)/2]){
			std::swap(array[tmp], array[(tmp-1)/2]);
			tmp = (tmp-1)/2;
		}
		n++;
	}
	long long extract(){
		int ret = array[0];
		n--;
		std::swap(array[0],array[n]);
		int tmp = 0;
		while(2*tmp+1 <= n-1){
			if(2*tmp+2 <= n-1){
				if(array[2*tmp+2] > array[tmp] && array[2*tmp+2] >= array[2*tmp+1]){
					std::swap(array[2*tmp+2],array[tmp]);
					tmp = 2*tmp+2;
				}else if(array[2*tmp+1] > array[tmp] && array[2*tmp+1] >= array[2*tmp+2]){
					std::swap(array[2*tmp+1],array[tmp]);
					tmp = 2*tmp+1;
				}else{
					break;
				}
			}else{
				if(array[tmp] < array[2*tmp+1]){
					std::swap(array[tmp],array[2*tmp+1]);
					tmp = 2*tmp+1;
				}else{
					break;
				}
			}
		}
		return ret;
	}

private:
	long long* array;
	int n;
};

int main(){

	long long insert_data;
	char buf[22];
	Heap heap;

	while(true){
		fgets(buf,22,stdin);
		if(buf[2] == 'd') break;
		if(buf[0] == 'i'){
			insert_data = 0;
			for(int i = 0; buf[i] != '\0';i++){
				if(buf[i] >= '0' && buf[i] <= '9'){
					insert_data = 10*insert_data + (buf[i] - '0');
				}
			}
			heap.insert(insert_data);
		}else{
			printf("%lld\n",heap.extract());
		}
	}
}