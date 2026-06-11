#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class MaxHeap{
private:
	vector<T> d;
public:
	void push(T t){
		d.push_back(t);
	}
	void maxHeapify(int k){
		int l = 2 * k + 1;
		int r = 2 * k + 2;
		T largest;
		if(l < d.size() && d[l] > d[k]) largest = l;
		else largest = k;

		if(r < d.size() && d[r] > d[largest]) largest = r;

		if(largest != k){
			swap(d[k], d[largest]);
			maxHeapify(largest);
		}
	}
	void buildMaxHeap(){
		for(int i = d.size() / 2; i >= 0; i--){
			maxHeapify(i);
		}
	}
	void printHeap(){
		for(int i = 0; i < d.size(); i++){
			cout << " " << d[i];
		}
		cout << endl;
	}
};

int main(){
	int h;
	cin >> h;
	MaxHeap<int> mh;
	for(int i = 0; i < h; i++){
		int a;
		cin >> a;
		mh.push(a);
	}
	mh.buildMaxHeap();
	mh.printHeap();
}